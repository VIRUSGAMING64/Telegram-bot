"""
Debug1 = Thread(target=PrintClientOnChange)
Debug1.start()
"""
from email import message
import time as tm
import socket as sk
clients = []
sock = ''
messages = []
timeout = 100
###Config Socket ###############

def CreateSock(port=1024):
    global sock
    try:
        sock = sk.socket()   
        sock.bind(('localhost',port))
        sock.listen(65535)
    except:
        CreateSock(port+1)

def GetConect(sock:sk.socket):
    global clients,timeout
    #print('debuging1...\n')
    try:
        sock.settimeout(timeout/1000)
        r = sock.accept()
        clients.append(r)
    except:
        return
    pass

def PrintClientOnChange():
    global clients
    ant = len(clients)
    #print('debuging2...\n')
    if(len(clients)!=ant):
        ant = len(clients)
        for cli in clients:
            for i in cli:
                print(i)
            print('\n')


def GetMessage():
    global clients,timeout
    tm.sleep(timeout/1000)
    #print('debuging3...\n')
    for client in clients:
        try:
            client[0].settimeout(timeout/1000)
            msg = client[0].recv(65535)
            msg.decode()
            messages.append([msg,client])
            client[0].settimeout(0)
        except:
            client[0].settimeout(0)
            pass
def HandleMessages(cli,addr,msg):
    return "TODO"

def ReplyMessage():
    global messages
    #print('debuging4...\n')
    if len(messages) == 0:
        tm.sleep(0.001)
    while(len(messages) > 0):
        msg = messages[0][0]
        cli = messages[0][1][0]
        addr = messages[0][1][1]
        messages.pop(0)
        msg = HandleMessages(cli,addr,msg).encode()
        cli.send(msg)

CreateSock()
op = 0
if(op != 1):
    while True:
        GetConect(sock)
        GetMessage()
        ReplyMessage()
else:
    sock = sk.socket()
    ip = ''
    while ip == '':
        ip = input('IP: ')
    port = ''
    while port == '':
        port = input('PORT: ')
    it = 0
    while True:
        try:
            sock.connect((ip,int(port)))
            break
        except:
            print(it+1)
            it = it + 1
        if it == 10:
            break
    GetMessage()
    res = input().encode()
    for i in messages:
        print(i[0][0][0] + '\n')
    sock.send(res)