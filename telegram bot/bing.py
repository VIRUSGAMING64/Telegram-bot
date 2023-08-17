import requests
import websocket  # pip install websocket-client
from typing import Callable, List
from json import loads, dumps
from uuid import uuid4
from random import *
import os


class BingAI:
    CUSTOM_HEADERS = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/113.0.1774.57"
    }

    MESSAGE_TEMPLATE = {
        "arguments": [
            {
                "source": "cib",
                "optionsSets": [
                    "nlu_direct_response_filter",
                    "deepleo",
                    "disable_emoji_spoken_text",
                    "responsible_ai_policy_235",
                    "enablemm",
                    "h3imaginative",
                    "nointernalsugg",
                    "dsblhlthcrd",
                    "intmvgnd",
                    "rweasgv2",
                    "dv3sugg",
                    "clgalileo",
                    "gencontentv3",
                    "dv3latencyv4",
                ],
                "allowedMessageTypes": [
                    "ActionRequest",
                    "Chat",
                    "Context",
                    "InternalSearchQuery",
                    "InternalSearchResult",
                    "Disengaged",
                    "InternalLoaderMessage",
                    "Progress",
                    "RenderCardRequest",
                    "AdsQuery",
                    "SemanticSerp",
                    "GenerateContentQuery",
                    "SearchQuery",
                ],
                "sliceIds": [
                    "winmuid1tf",
                    "pref3",
                    "winshortmsgtf",
                    "sydtransl",
                    "sydconfigoptt",
                    "nodupeventsc",
                    "convcssclick",
                    "modrankw",
                    "530psthos0",
                    "606rai271s0",
                    "505scsv5",
                    "602refusals0",
                    "418dhlth",
                    "606rlv4",
                    "525glv7_b",
                    "529rwea",
                ],
                "verbosity": "verbose",
                "traceId": "",
                "isStartOfSession": True,
                "message": {
                    "locale": "es-ES",
                    "market": "es-ES",
                    "region": "ES",
                    "author": "user",
                    "inputMethod": "Keyboard",
                    "text": "",
                    "messageType": "Chat",
                    "requestId": "",
                    "messageId": "",
                },
                "tone": "Creative",
                "requestId": "",
                "conversationSignature": "",
                "participant": {"id": ""},
                "spokenTextMode": "None",
                "conversationId": "",
            }
        ],
        "invocationId": 0,
        "target": "chat",
        "type": 4,
    }

    def __init__(self) -> None:
        self.chat: List[dict] = []
        self.client_id: str = ""
        self.conversation_id: str = ""
        self.conversation_signature: str = ""
        self.trace_id: str = ""
        self._session = requests.Session()

    def new_conversation(self):
        ret = self._session.get(
            "https://www.bing.com/turing/conversation/create",
            headers=self.CUSTOM_HEADERS,
        ).json()

        if ret["result"]["value"] != "Success":
            raise Exception(ret["result"]["message"])
        myrand = Random()
        self.conversation_id = ret["conversationId"]
        self.client_id = ret["clientId"]
        self.conversation_signature = ret["conversationSignature"]
        self.trace_id = myrand.randbytes(16).hex()

    def ask(self, text: str, progress_callback: Callable | None = None):
        if not (
            self.client_id
            and self.conversation_id
            and self.conversation_signature
            and self.trace_id
        ):
            raise Exception(
                "There's no active conversation, use new_conversation() to create one."
            )

        message_id: str = str(uuid4())

        payload: dict = self.MESSAGE_TEMPLATE.copy()
        payload["invocationId"] = str(len(self.chat))
        payload["arguments"][0]["isStartOfSession"] = False if self.chat else True
        payload["arguments"][0]["conversationSignature"] = self.conversation_signature
        payload["arguments"][0]["conversationId"] = self.conversation_id
        payload["arguments"][0]["participant"]["id"] = self.client_id
        payload["arguments"][0]["traceId"] = self.trace_id
        payload["arguments"][0]["requestId"] = message_id
        payload["arguments"][0]["message"]["requestId"] = message_id
        payload["arguments"][0]["message"]["messageId"] = message_id
        payload["arguments"][0]["message"]["text"] = text

        ws = websocket.WebSocket()
        ws.connect("wss://sydney.bing.com/sydney/ChatHub")
        ws.send(dumps({"protocol": "json", "version": 1}) + "\x1e")
        ws.send(dumps(payload) + "\x1e")

        progress_text: str = ""
        recv = 1
        while recv:
            recv = ws.recv().split("\x1e")
            for response in recv:
                try:
                    data: dict = loads(response)
                    # print(str(data)[:180])  # Debug
                except:
                    continue

                if data.get("type") == 6:  # Ping
                    ws.send(dumps({"type": 6}) + "\x1e")  # Pong

                elif data.get("type") == 1:  # En progreso
                    if progress_callback:
                        try:
                            progress_message: list = data.get("arguments", [{}])[0].get(
                                "messages", [{}]
                            )[0]
                            new_text = (
                                progress_message.get("adaptiveCards", [{}])[0]
                                .get("body", [{}])[0]
                                .get("text")
                            ) or progress_message.get("text")

                            if new_text and new_text != progress_text:
                                progress_text = new_text
                                progress_callback(new_text)
                        except Exception:
                            pass

                elif data.get("type") == 2:  # Respuesta completa
                    messages: list = data.get("item", {}).get("messages", [])

                    try:
                        response_message: dict = (
                            message
                            for message in messages
                            if message.get("author") == "bot"
                            and message.get("text")
                            and not message.get("messageType")
                        ).__next__()
                    except Exception:
                        raise Exception("Could not retrieve any viable message")

                    resp_text = (
                        response_message.get("adaptiveCards", [{}])[0]
                        .get("body", [{}])[0]
                        .get("text")
                    ) or response_message.get("text")

                    self.chat.append({"user": text, "bot": resp_text})

                    ws.close()
                    return resp_text


def callback(text: str):
    columns = os.get_terminal_size().columns
    text = "Respuesta: " + text
    lines = text.split("\n")
    uplines = len(lines) - 1
    uplines += sum([len(line) // columns for line in lines])
    if uplines:
        print(
            (uplines + 1) * (columns * " " + "\n"),
            end="\r",
        )
        print(f"\033[{uplines+1}A", end="")
        print(text, end="\r", flush=True)
        print(f"\033[{uplines}A", end="")
    else:
        print(text, end="\r", flush=True)


if __name__ == "__main__":
    ai = BingAI()  # ejemplos
    ai.new_conversation()
    questions = [
        "Que es Minecraft??",
        "Que es un segment tree",
    ]

    for question in questions:
        print("Pregunta:", question)
        print("Respuesta:", ai.ask(question))
