import threading as th
import socket as sk
sock = sk.socket()
PORT = 8082
IP = ""
DEFAULTTIMEOUT = 0
CLIENTS = []
sock.bind((IP,PORT))
sock.listen(65535)

def GetClient():
    global CLIENTS,sock,DEFAULTTIMEOUT
    sock.settimeout(100)
    try:
        cli,addr  = sock.accept()
    except:
        sock.settimeout(DEFAULTTIMEOUT)
        return
    sock.settimeout(DEFAULTTIMEOUT)
    CLIENTS.append([cli,addr])

def GetMessage():
    global CLIENTS,sock,DEFAULTTIMEOUT
    MSGS = []
    for i in range(len(CLIENTS)):
        try:
            CLIENTS[i][0].settimeout(1000)
        except:
            pass
def serv():
    global CLIENTS,sock,DEFAULTTIMEOUT
    while True:
        GetClient()
        msg = GetMessage()
        for i in msg:
            print(i)

serv()