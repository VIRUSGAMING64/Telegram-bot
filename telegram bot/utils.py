import os
import threading as th
import os.path as path
from log import *
from pyrogram.types import Message

async def progres(current, total):
    s = f"{current * 100 / total:.1f}%"
    print(s)

def dir(s):
    if s == "/cd":
        return os.getcwd()
    return ""

def chdir(s):
    try:
        os.chdir(s)
        return "directory change to " + s
    except:
        return "impossible change directory..."


def dirs(s):
    if s == "/dir":
        ls = os.listdir()
        x = ""
        for i in ls:
            try:
                n = open(i)
                n.close()
                x += "file:   " + i + "\n"
            except:
                x += "directory:   " + i + "\n"
        return x
    else:
        return ""


def sysinfo(s):
    if s == "/system_info":
        try:
            os.system("systeminfo > m")
            f = open("m")
            line = f.read(65536)
            msg = line
            while line:
                line = f.read(65536)
                msg += line
            return msg
        except:
            return "access denied"
    else:
        return ""


def helps(s):
    if s == "/help":
        m = [
            "/help",
            "/secure_on",
            "/secure_off",
            "/sendfile",
            "/cd",
            "/dir",
            "/chdir",
            "/system_info",
            "/chmod",
            "/getlog",
            "/alert",
            "/notepad",
        ]
        msg = ""
        for i in m:
            msg += i + "\n"
        return msg
    else:
        return ""


def secure(message):
    if message == "/secure_on":
        open("SecureKey", "wb").close()
        return "secure_on"
    elif message == "/secure_off":
        try:
            os.remove("SecureKey")
        except:
            pass
        return "secure_off"
    else:
        return ""


def cmd(comand):
    os.system(comand + "> F.txt")
    file = open("F.txt", "r")
    line = file.read(65535)
    res = line
    while line:
        line = file.read(65535)
        res += line
    file.close()
    os.remove("F.txt")
    return res

def GetLog(matrix = 0):
    log = loger("log_file.log")
    data = log.read()
    data = log.decode(data)
    data = log.decode_list(data)
    res = ""
    if matrix == 1:
        for i in range(len(data)):
            data[i][1] = int(data[i][1])
        return data
    dato = []
    for L in data:
        for i in L:
            res += i + ", "
            if len(res) >= 3800:
                dato.append(res)
                res = ""
        res += "\n"
    dato.append(res)
    return dato


def commandos(s, CMD=False):
    x = ""
    if CMD:
        x = cmd(s)
    else:
        x += secure(s)
        x += helps(s)
        x += dir(s)
        x += dirs(s)
        x += sysinfo(s)
    if x == "":
        x = "no commands..."
    return x


def CheckSecure():
    l = os.listdir()
    if "SecureKey" in l:
        return True
    else:
        return False


print('module loaded: "utils"')
