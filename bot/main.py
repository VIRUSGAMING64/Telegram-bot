from pyrogram import Client, filters
from utils import *

API_ID = 29695292
API_HASH = "8b05ce00146edeeae7aafc4bea30e713"
whait_for_filename = False

bot = Client("bot", API_ID, API_HASH)

@bot.on_message(filters.private)
async def on_message(client,message):
    global whait_for_filename
    ID = message.chat.id
    msg = message.text
    if(whait_for_filename == True):
        whait_for_filename = False
        await bot.send_document(ID,msg)
        return
    elif(message.text == '/sendfile'):
        await bot.send_message(ID,'send file name')
        whait_for_filename = True
        return
    else:
        cmd = command(msg)   
        if cmd == "":
            cmd = "no commands..."
    try:
        await bot.send_message(ID,cmd)
    except:
        pass

bot.run()
