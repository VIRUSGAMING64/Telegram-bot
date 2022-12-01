import socket
import os
import os.path as path
import threading as th
class queue:
    que = []
    def __init__():
        pass
    @classmethod
    def push(self,item):
        self.que.append(item)
    @classmethod
    def front(self):
        if(len(self.que)>=1):
            return self.que[0]
        return 'nan'
    @classmethod
    def pop(self):
        try:
            self.que.pop(0)
        except:
            return 0
        return 1

class serv:
    """Basic TCP/IP server"""
    SOCK = ""
    IP = ""
    PORT = 0
    def serv(self,ip = "localhost", port = 60000):
        self.IP = ip
        self.PORT = port
        self.SOCK = socket.socket()
    def bind(self):
        self.SOCK.bind((self.IP,self.PORT))
    
    def accept(self):
        return self.SOCK.accept()
    def SetTimeOut(self,n):
        self.SOCK.settimeout(n)
        
def get_access(rute):
    try:
        os.access(rute,3)
        os.chdir(rute)
        return 1
    except:
        return 0

def getfiles(rute):
    act = os.getcwd()
    files = []
    try:
        os.access(rute,3)
        os.chdir(rute)
        files = os.listdir()
    except:
        print('Error in rute\n')
    os.access(act,3)
    os.chdir(act)
    return files

def filetomem(rute):
    try:
        file = open(rute,'rb')
    except:
        print('file not found :(\n')
        return ''
    line = file.read(65535)
    mem = b''
    mem+= line
    while(line):
        line = file.read(65535)
        mem += line
    file.close()
    return mem

def size(rute):
    try:
        a = path.getsize(rute)
        return (a)
    except:
        return -1

def file_chunk(file):
    size = path.getsize(file)
    chunktam = size//65535
    file = open(file,'rb')
    chunks = []
    line = file.read(chunktam)
    chunks.append(line)
    while(line):
        line = file.read(chunktam)
        chunks.append(line)
    return chunks

def sieve(n):
    l = list(range(n+1))
    l[0]=-1
    l[1]=-1
    i = 4

    while(i<n):
        l[i] = -1
        i+=2
    i=2

    while(i*i<=n):
        if l[i]!=-1:
            j = i*i
            while(j<=n):
                l[j] = -1
                j+=i*2
        i+=1
    h = l
    l = []
    for i in h:
        if i!=-1:
            l.append(i)
    return l

def makeG(n,m):
    g = []
    for i in range(n):
        g.append([])
    for i in range(m):
        a = int(input())
        b = int(input())
        g[a].append(b)
        g[b].append(a)
    return g

def Remove(str):
    os.remove(str)

def CreateDirectory(str):
    try:
        os.mkdir(str)
        return True
    except:
        return False