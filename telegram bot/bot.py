from utils import *

# GLOBAL VARIABLES
API_ID = 29695292
API_HASH = "8b05ce00146edeeae7aafc4bea30e713"
ALERT = 0
ACTUAL_MESSAGE = ""
TotalUsers = []
WAITING_FOR_FILENAME = 0
CMD = 0
CHANGE_DIR = 0
NOTEPAD_FILENAME = 0
GETING_FILENAME = 0
WRITING = 0
MAX_MESSAGE_LENGTH = 4096
GETING_URL = 0
WORKERS = 16
ASKING = 0
DOWNLOADER = ""
bot = Client("bot", API_ID, API_HASH, workers=WORKERS)
LAST_MEDIA_DOWNLOADED = ""
log = loger("log_file.log")
TotalUsers = log.read()
LAST_MESSAGE_DOWNLOAD = ""
# END GLOBAL VARIABLES


async def progres(current, total):
    global LAST_MESSAGE_DOWNLOAD, LAST_MEDIA_DOWNLOADED, DOWNLOADER
    try:
        s = f"{current * 100 / total:.1f}%"
        porcent = current * 100 / total
        MSG = str(
            str("* " * int(int(porcent) // 10))
            + str(". " * (10 - (int(porcent) // 10)))
            + "\n"
            + str(s)
        )
        MSG = Fill_Border(MSG)
        print(MSG)
        if LAST_MESSAGE_DOWNLOAD == "":
            try:
                LAST_MESSAGE_DOWNLOAD = await bot.send_message(DOWNLOADER, MSG)
            except Exception as e:
                print("error on first msg: ", e)
        else:
            try:
                await bot.edit_message_text(
                    chat_id=LAST_MESSAGE_DOWNLOAD.chat.id,
                    message_id=LAST_MESSAGE_DOWNLOAD.id,
                    text=MSG,
                )
            except:
                print("error on edit")
    except:
        print("error on id for download")

async def Download(message, user_id):
    global DOWNLOADER,LAST_MESSAGE_DOWNLOAD
    try:
        if DOWNLOADER != "":
            return
    except:
        print("error on check current download")
    try:
        DOWNLOADER = user_id
        LAST_MEDIA_DOWNLOADED = await bot.download_media(message, progress=progres)
        await bot.delete_messages(
            LAST_MESSAGE_DOWNLOAD.chat.id, LAST_MESSAGE_DOWNLOAD.id
        )
    except Exception as e:
        DOWNLOADER = ""
        if str(e) == "This message doesn't contain any downloadable media":
            DOWNLOADER = ""
        else:
            print(e)
    finally:
        LAST_MESSAGE_DOWNLOAD = ""
        DOWNLOADER = ""


@bot.on_message()
async def on_message(client, message):
    global WAITING_FOR_FILENAME, log, CHANGE_DIR, CMD, TotalUsers, ALERT, WRITING, GETING_FILENAME
    global ASKING, NOTEPAD_FILENAME, ACTUAL_MESSAGE,GETING_URL
    cmd = ""
    chat_type = message.chat.type
    ACTUAL_MESSAGE = message
    ID = message.chat.id
    rute = os.getcwd()
    msg = message.text
    user = message.from_user.first_name
    await Download(message, ID)

    if msg == None:
        return  # no text in message
    
    # check if user is new
    data = "[" + str(user) + "," + str(ID) + "]"
    find = 0
    if data in TotalUsers:
        find = 1
    if find == 0:
        print("User: " + user + " is new")
        log.write(data)
        TotalUsers = log.read()
    # endregion
    # chatgpt mode 
    if (msg == "/ask"):
        ASKING = not ASKING
        await bot.send_message(ID,"asking: " + str(ASKING))
        return
    if ASKING:
        ANT = await bot.send_message(ID,"thinking...")
        await bot.send_message(ID,ask_q(msg))
        await bot.delete_messages(ANT.chat.id,ANT.id)
        return 
    #endregion
    
    # notepad mode
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
        if GETING_FILENAME:
            GETING_FILENAME = 0
            NOTEPAD_FILENAME = msg
            file = open(msg, "w")
            file.close()
            return
        file = open(NOTEPAD_FILENAME, "a")
        file.write(msg)
        file.close()
        return
    # endregion

    # cambia a consola y biseversa
    if msg == "/chmod":
        CMD = not CMD
        if CMD:
            await bot.send_message(ID, "Chat mode changed to Command Prompt")
        else:
            await bot.send_message(ID, "Chat mode change to normal bot")
        return
    # endregion
    if GETING_URL:
        GETING_URL = 0
        try:
            msg = msg.split(' ')
            await bot.send_message(ID,urlget(msg[0],msg[1]))
        except:
            await bot.send_message(ID,"Error on your message")
        pass
        return
    if "/urlget" in msg:
        msg = msg.split(' ')
        pos = -1
        for i in range(len(msg)):
            if msg[i] == "/urlget":
                pos = i+1
                break
        if pos == len(msg):
            GETING_URL = 1
            await bot.send_message(ID,"send url and filename separated by spaces")
            return
        TEMP = await bot.send_message(ID,"downloading")
        try:
            await bot.send_message(ID,urlget(msg[pos],msg[pos+1]))
        except:
            await bot.edit_message_text(TEMP.chat.id,TEMP.id,"Error on command sintax")
            return
        await bot.delete_messages(ID,TEMP.id)
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
        TEMP = await bot.send_message(ID, "uploading to telegram...")
        await bot.send_document(ID, msg)
        await bot.delete_messages(TEMP.chat.id, TEMP.id)
        return 
    elif message.text == "/sendfile":
        await bot.send_message(ID, "Send file name")
        WAITING_FOR_FILENAME = True
        return
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

def timer():
    global START_TIME
    while 1:
        sleep(600)
        print("10 mins")
        try:
            bot.stop()
            res = rq.get("https://api.render.com/deploy/srv-cj5gqlqcn0vc73bqcfa0?key=MX44ixu4pCk")
            JS=res.json()
            print(JS)
            exit(0)
        except:
            pass
TH = th.Thread(target=timer)
TH.start()
bot.run()
