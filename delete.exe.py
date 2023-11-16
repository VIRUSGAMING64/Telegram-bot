from genericpath import isdir, isfile
import os
import threading as th
from pathlib import *
file = None
dele = 0

def dfs(directory:str,hides = True):
    global file,dele
    #print(directory)
    try:
        if(directory.startswith(".") and hides == False):
            return 
        if directory.endswith(".out") or directory.endswith(".exe") or directory.endswith(".in") or directory.endswith(".bin") or directory.startswith("."):
            try:    
                os.remove(directory)
                print(directory)
                file.write(directory+"\n")
                dele+=1
                return
            except Exception as e:
                try:
                    os.removedirs(directory)
                    print(directory)
                    file.write(directory+"\n")
                    dele+=1
                except Exception as e: #dir not empty
                    pass
    except Exception as e:
        print(e)
        return
    try:
        os.access(directory, 3)
        os.chdir(directory)
        l = os.listdir()
    except Exception as e:
        return
    for i in l:
        #print(i)
        dfs(i,hides)
path = os.getcwd()
i = input("delete all .exe in " + path + " ?  Y/N  > ")

try:
    file = open("delexe.log","rb")
    file.close()
except:
    pass
finally:
    file = open("delexe.log","a")

if i == "Y" or i == "y":
    dfs(path)
    print("total deletions: ",dele)
