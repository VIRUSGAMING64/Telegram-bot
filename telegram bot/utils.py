import os
import os.path as path
from pyrogram import Client, filters

def dir(s):
    if(s == '/cd'):
        return os.getcwd()
    return ""

def chdir(s):
    try:
        os.chdir(s)
        return "directory change to " + s
    except:
        return "impossible change directory..."

def dirs(s):
    if(s == '/dir'):
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

def sysinfo(s):
    if(s == '/system info'):
        try:
            os.system('systeminfo > m')
            f = open('m')
            line = f.read(65536)
            msg = line
            while(line):
                line = f.read(65536)
                msg+=line
            return msg
        except:
            return "access denied"
    else:
        return ""

def helps(s):
    if(s=='/help'):
        m = [
            "/sendfile",
            "/cd",
            "/dir",
            "/chdir",
            "/system info"
        ]
        msg = ""
        for i in m:
            msg+=i+"\n"
        return msg
    else:
        return ""

def command(s):
    x = ""
    x+= helps(s)
    x += dir(s)
    x += dirs(s)
    x+= sysinfo(s)
    return x