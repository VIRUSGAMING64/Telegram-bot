from ctypes import WinDLL
from genericpath import isdir, isfile
import os
import threading as th
from pathlib import *
file = None
dele = 0

def dfs(path:str):
    global file,dele
    try:
        if path.endswith(".out") or path.endswith(".exe") or path.endswith(".in") or path.endswith(".bin")  or path.startswith("."):
            print(path)
            file.write(path+"\n")
            dele+=1
            os.remove(path)
    except:
        return
    try:
        os.access(path, 3)
        os.chdir(path)
        l = os.listdir()
    except:
        return
    for i in l:
        res = path + "\\" + i
        res = th.Thread(target=dfs, args=[res])
        res.start()
path = os.getcwd()
i = input("delete all .exe in " + path + " ?  Y/N  > ")

os.access("c:/users/public/",3)
try:
    file = open("c:/users/public/delexe.log","rb")
    file.close()
except:
    pass
finally:
    file = open("c:/users/public/delexe.log","a")

if i == "Y" or i == "y":
    dfs(path)
    print("total deletions: ",dele)
