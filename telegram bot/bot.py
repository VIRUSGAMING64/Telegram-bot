from pyrogram import Client, filters
import os
import os.path as path
from pyrogram.types import Message
from utils import *
from time import *
#INSTALLS   
# GLOBAL VARIABLES
API_ID = 29695292
API_HASH = "8b05ce00146edeeae7aafc4bea30e713"
bot = Client("bot", API_ID, API_HASH)
TotalUsers = []
WAITING_FOR_FILENAME = 0
CHANGE_DIR = 0
NOTEPAD_FILENAME = 0
CMD = 0
ALERT = 0
GETING_FILENAME = 0
ACTUAL_MESSAGE = ""
WRITING = 0
MAX_MESSAGE_LENGTH = 4096
WORKERS = 16
ASKING = 0
DOWNLOADER = ""
# END GLOBAL VARIABLES
bot = Client("bot", API_ID, API_HASH, workers=WORKERS)  
log = loger("log_file.log")
TotalUsers = log.read() 
LAST_MESSAGE = ""
async def progres(current, total):
    global LAST_MESSAGE,DOWNLOADER
    try:
        s = f"{current * 100 / total:.1f}%"
        print(s)
        if(LAST_MESSAGE == ""):
            LAST_MESSAGE = await bot.send_message(DOWNLOADER,str(s))   
        else:
            try:
                await bot.edit_message_text(chat_id=LAST_MESSAGE.chat.id,message_id=LAST_MESSAGE.id,text=str(s))
            except:
                print("error on edit")
    except:
        print("error on id for download")

async def Download(message,user_id):
    global DOWNLOADER
    try:
        if(DOWNLOADER != ""):
            await bot.send_message(user_id,"current download please wait")
            return
    except:
        print("error on check current download")
    try:
        DOWNLOADER = user_id
        await bot.download_media(message,progress=progres)
    except:    
        DOWNLOADER = ""
        pass
    finally:
        LAST_MESSAGE = ""
        DOWNLOADER = ""

@bot.on_message()
async def on_message(client, message):
    global WAITING_FOR_FILENAME, log, CHANGE_DIR, CMD, TotalUsers, ALERT, WRITING,GETING_FILENAME
    global ASKING,NOTEPAD_FILENAME,ACTUAL_MESSAGE
    cmd = ""
    chat_type = message.chat.type
    ACTUAL_MESSAGE = message
    ID = message.chat.id
    rute = os.getcwd()
    msg = message.text
    user = message.from_user.first_name
    find = 0
    data = "[" + str(user) + "," + str(ID) + "]"

    await Download(message,ID)
    if msg == None:
        return #no text in message
    
    if data in TotalUsers:
        find = 1

    if find == 0:
        print("User: " + user + " is new")
        log.write(data)
        TotalUsers = log.read()

    print("Message From: ", user, " ", msg)
    
    if msg == "/notepad":
        WRITING = not WRITING
        if WRITING:
            await bot.send_message(ID, "Notepad mode on...")            
            await bot.send_message(ID, "Send filename please")
            GETING_FILENAME = 1
        else:
            await bot.send_message(ID, "Notepad mode off...")
        return
    if WRITING:
        if(GETING_FILENAME):
            GETING_FILENAME = 0
            NOTEPAD_FILENAME = msg
            file = open(msg,"w")
            file.close()
            return 
        file = open(NOTEPAD_FILENAME,"a")
        file.write(msg)
        file.close()
        return

    if msg == "/chmod":
        CMD = not CMD
        if CMD:
            await bot.send_message(ID, "Chat mode changed to Command Prompt")
        else:
            await bot.send_message(ID, "Chat mode change to normal bot")
        return

    if msg == "/alert":
        if user != "VIRUSGAMING":
            await bot.send_message(ID, "Access denied...")
            return
        ALERT = not ALERT
        if ALERT:
            await bot.send_message(ID, "Chat mode change to alert all users")
        else:
            await bot.send_message(ID, "Chat mode change to normal bot")
        return

    if ALERT:
        M = GetLog(1)
        for i in range(len(M)):
            if M[i][1] == ID:
                continue
            await bot.send_message(M[i][1], msg)
        return

    if msg == "/getlog":
        datas = GetLog()
        for text in datas:
            await bot.send_message(ID, text)
        return

    if CMD:
        msg = commandos(msg, CMD)
        if len(msg) >= MAX_MESSAGE_LENGTH:
            ms = ""
            for i in msg:
                ms += i
                if len(ms) == MAX_MESSAGE_LENGTH:
                    await bot.send_message(ID, ms)
                    sleep(0.500)
                    ms = ""
            await bot.send_message(ID, ms)
            # await bot.send_document(ID, "F.txt")
        else:
            await bot.send_message(ID, msg)
        return

    if user != "VIRUSGAMING" and CheckSecure():
        await bot.send_message(ID, "Access denied...")
        return

    if msg == "/chdir":
        await bot.send_message(ID, "Enter directory name: ")
        CHANGE_DIR = True
        return

    elif CHANGE_DIR == True:
        CHANGE_DIR = False
        msg = chdir(msg)
        await bot.send_message(ID, msg)

    elif WAITING_FOR_FILENAME == True:
        WAITING_FOR_FILENAME = False
        await bot.send_document(ID, msg)

    elif message.text == "/sendfile":
        await bot.send_message(ID, "Send file name")
        WAITING_FOR_FILENAME = True

    else:
        cmd = commandos(msg, 0)

    try:
        await bot.send_message(ID, cmd)
    except:
        pass


@bot.on_edited_message()
async def on_edited_message(client, message):
    await on_message(client, message)


@bot.on_deleted_messages()
async def on_deleted_messages(client, message):
    bot.send_message(message.chat.id, "lo borraste...")

bot.run()
