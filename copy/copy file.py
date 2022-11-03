import os
import os.path as path
def get_access(rute):
    try:
        os.access(rute,3)
        os.chdir(rute)
        return 1
    except:
        return 0

def copy(file,to):
    actrute = os.getcwd()
    chunk = 65536*2-1
    try:
        file = open(file,'rb')
    except:
        print('file not found !!!')
        return
    print('loading...')
    name = path.basename(file.name)
    line = file.read(chunk)
    get_access(to)
    fileto = open(name,'wb')
    fileto.write(line)
    while(line):
        line = file.read(chunk)
        fileto.write(line)
    fileto.close()
    file.close()
    get_access(actrute)
    print('copied!!!')
