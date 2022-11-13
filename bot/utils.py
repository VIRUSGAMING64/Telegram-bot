import os
import os.path as path
from pyrogram import Client, filters

def dir(s):
    if(s == '/dir'):
        return os.getcwd()
    return ""

def dirs(s):
    if(s == '/files'):
        ls = os.listdir()
        x = ""
        for i in ls:
            try:
                n = open(i)
                n.close()
                x+= "file:   "+i+"\n"
            except:
                x+= "directory:   "+i+"\n"
        return x
    else:
        return ""

def command(s):
    x = ""
    x += dir(s)
    x += dirs(s)
    return x