import os
from pyrogram.raw import *
import threading as th
import os.path as path
from pyrogram import Client,filters
from pyrogram.types import Message
from time import *

def Fill_Border(MSG):
    ms ="+"*24+"\n"
    ME = ""
    for i in range(len(MSG)):
        if MSG[i] == "\n":
            ME += MSG[i]
            ME+=" "*9
            continue
        ME+=MSG[i]
    return ms+ME+"\n"+ms

class loger:
    file_log_name = "log_file.log"
    file_size = None

    @classmethod
    def __init__(self):
        print("loger created empty")

    @classmethod
    def __init__(self, file):
        if path.exists(file):
            print("loaded exists log file")
            self.file_log_name = file
        else:
            print("creating new log file")
            file = open(file, 'w')
            file.close()

    @classmethod
    def CreateNew(self, file):
        new = loger(file)
        self = new
        return new

    @classmethod
    def write(self, data: str):
        file = open(self.file_log_name, "a")
        file.write(data+"\n")
        file.close()

    @classmethod
    def read(self):
        file = open(self.file_log_name, "r")
        line = file.read(65536)
        text: str = line
        while line:
            line = file.read(65536)
            text += line
        file.close()
        return text

    @classmethod
    def decode(self, text):
        list = []
        str = ""
        for i in range(len(text)):
            if text[i] == "[":
                str = ""
                continue
            if text[i] == "]":
                list.append(str)
                str = ""
                continue
            str += text[i]
        return list

    def decode_list(self, lista):
        result = []
        for data in lista:
            str = ""
            res = []
            for i in range(len(data)):
                if data[i] == ",":
                    res.append(str)
                    str = ""
                    continue
                str += data[i]
            res.append(str)
            result.append(res)
        return result



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
    if x == "":
        x = "no commands..."
    return x


def CheckSecure():
    l = os.listdir()
    if "SecureKey" in l:
        return True
    else:
        return False
