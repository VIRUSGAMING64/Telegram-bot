const crypto = require("crypto");
const WebSocket = require("faye-websocket"); // npm install faye-websocket

class bingRequest {
    constructor(type, invocationId, target, args) {
        this.arguments = args;
        this.invocationId = typeof invocationId != "undefined" ? invocationId.toString() : undefined; // Microsoft is weird
        this.target = target;
        this.type = type;
    }
}

class bingMessage {
    constructor(locale, author, inputMethod, text, messageType, requestId, messageId) {
        this.locale = locale;
        this.author = author;
        this.inputMethod = inputMethod;
        this.text = text;
        this.messageType = messageType;
        this.requestId = requestId;
        this.messageId = messageId;
    }
}

class bingParticipant {
    constructor(id) {
        this.id = id;
    }
}

class bingMessageQuery {
    constructor(conversationId, conversationSignature, participant, traceId, isStartOfSession, message, tone, source, optionsSets, allowedMessageTypes, sliceIds, verbosity, requestId, spokenTextMode) {
        this.source = source;
        this.optionsSets = optionsSets;
        this.allowedMessageTypes = allowedMessageTypes;
        this.sliceIds = sliceIds;
        this.verbosity = verbosity;
        this.traceId = traceId;
        this.isStartOfSession = isStartOfSession;
        this.message = message;
        this.tone = tone;
        this.requestId = requestId;
        this.conversationSignature = conversationSignature;
        this.participant = participant;
        this.spokenTextMode = spokenTextMode;
        this.conversationId = conversationId;
    }
}

class bingChat {
    constructor(clientId, conversationId, conversationSignature, traceId) {
        this.messageHistory = [];
        this.clientId = clientId;
        this.conversationId = conversationId;
        this.conversationSignature = conversationSignature;
        this.traceId = traceId;
    }

    async newConversation() {
        const customHeaders = { "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/113.0.1774.57" };
        const url = "https://www.bing.com/turing/conversation/create";
        const response = await fetch(url, { headers: customHeaders });
        const jsonResponse = await response.json();

        if (jsonResponse.result.value != "Success") {
            throw new Error(jsonResponse.result.message);
        }

        this.messageHistory = [];
        this.clientId = jsonResponse.clientId;
        this.conversationId = jsonResponse.conversationId;
        this.conversationSignature = jsonResponse.conversationSignature;
        this.traceId = crypto.randomBytes(16).toString("hex");
    }

    async ask(text, tone, locale, progessCallback) {
        const messageRequest = this.#createMessageRequest(this.conversationId, this.conversationSignature, this.clientId, this.traceId, this.messageHistory.length, tone, text, locale)
        const wsUrl = "wss://sydney.bing.com/sydney/ChatHub";

        let ws = new WebSocket.Client(wsUrl);       // For browser API it's just new WebSocket(url)

        ws.on('open', (event) => {                  // For browser API it's ws.addEventListener('open', (event) => {
            ws.send(JSON.stringify({ "protocol": "json", "version": 1 }) + "\x1e")
            ws.send(JSON.stringify(messageRequest) + "\x1e")
        });

        ws.on('close', (event) => {                 // For browser API it's ws.addEventListener('close', (event) => {
            ws = null;
        });

        ws.on('message', (event) => {               // For browser API it's ws.addEventListener('message', (event) => {
            const packets = event.data
                .split("\x1e")
                .map((str) => { try { return JSON.parse(str); } catch (e) { } })
                .filter((item) => item);

            for (const packet of packets) {

                if (packet.error) {
                    ws.close()
                    throw new Error(packet.error);
                }

                if (packet.type == 6) { // Ping
                    ws.send(JSON.stringify(new bingRequest(6))); // Pong
                    continue;
                }

                if (packet.type == 1 && progessCallback) {
                    try {
                        const botProgressMessage = packet.arguments[0].messages[0];
                        const botProgressText = this.#getMessageText(botProgressMessage);
                        if (botProgressText) { progessCallback(botProgressText); }
                    } catch { }
                    continue;
                }

                if (packet.type == 2) { // Completed
                    if (packet.item.result.error) {
                        ws.close()
                        throw new Error(packet.item.result.message)
                    }

                    const messages = packet.item.messages
                    const botResponseMessage = messages.filter((message) => message.author == "bot" && !message.messageType)[0]

                    if (!botResponseMessage) {
                        ws.close()
                        throw new Error(`Could not find suitable message. Full packet:\n${JSON.stringify(packet)}`)
                    }

                    const botResponseText = this.#getMessageText(botResponseMessage)

                    this.messageHistory.push({ userMessage: text, botResponse: botResponseText })
                    ws.close();
                }

            }
        });


        while (ws) {
            await (new Promise(resolve => setTimeout(resolve, 500)));
        }

        return this.messageHistory[this.messageHistory.length - 1].botResponse;
    }

    #getMessageText(message) {
        try {
            return message.adaptiveCards[0].body[0].text;
        } catch {
            return message.text || message.hiddenText;
        }
    }

    #createMessageRequest(conversationId, conversationSignature, clientId, traceId, invocationId, tone, text, locale) {
        const author = "user";
        const inputMethod = "Keyboard";
        const messageType = "Chat";
        const requestId = crypto.randomUUID();
        const messageId = requestId;
        const isStartOfSession = invocationId ? false : true;
        const source = "cib";
        const verbosity = "verbose";
        const spokenTextMode = "None";

        const optionsSets = ["nlu_direct_response_filter", "deepleo", "disable_emoji_spoken_text",
            "responsible_ai_policy_235", "enablemm", "h3imaginative", "nointernalsugg", "dsblhlthcrd",
            "intmvgnd", "rweasgv2", "dv3sugg", "clgalileo", "gencontentv3", "dv3latencyv4"];

        const allowedMessageTypes = ["ActionRequest", "Chat", "Context", "InternalSearchQuery",
            "InternalSearchResult", "Disengaged", "InternalLoaderMessage", "Progress", "RenderCardRequest",
            "AdsQuery", "SemanticSerp", "GenerateContentQuery", "SearchQuery"];

        const sliceIds = ["winmuid1tf", "pref3", "winshortmsgtf", "sydtransl", "sydconfigoptt", "nodupeventsc",
            "convcssclick", "modrankw", "530psthos0", "606rai271s0", "505scsv5", "602refusals0", "418dhlth",
            "606rlv4", "525glv7_b", "529rwea",];

        const participant = new bingParticipant(clientId);
        const message = new bingMessage(locale, author, inputMethod, text, messageType, requestId, messageId);
        const messageQuery = new bingMessageQuery(conversationId, conversationSignature, participant, traceId, isStartOfSession, message, tone, source, optionsSets, allowedMessageTypes, sliceIds, verbosity, requestId, spokenTextMode);
        const request = new bingRequest(4, invocationId, "chat", [messageQuery]);
        return request;
    }
}


function sampleCallback(text) {
    process.stdout.write(`Generando: ${text.length} caracteres...\r`)
}

async function main() {
    const chat = new bingChat();
    await chat.newConversation();
    console.log(chat)

    questions = ["Cuanto es 1+1", "Cuanto es 2+2", "Cuanto es 3+3", "Cuanto es 4+4", "Cuanto es 5+5",
        "Cuanto es 6+6", "Cuanto es 7+7", "Cuanto es 8+8", "Cuanto es 9+9", "Cuanto es 10+10", "Aun estas ahi?"]

    for (question of questions) {
        console.log("Pregunta: " + question)
        console.log("Respuesta: " + await chat.ask(question, "Creative", "es-ES", sampleCallback))
    }

}

main()
