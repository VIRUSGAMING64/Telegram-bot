import os
import os.path as path
def get_access(rute):
    try:
        os.access(rute,3)
        os.chdir(rute)
        return 1
    except:
        return 0

def copy_file(file,to):
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

def copy_dir(ini,end):
    os.access(ini,3)
    os.chdir(ini)
    files = os.listdir()
    for i in files:
        try:
            file = open(ini+'/'+i,'rb') 
            to_file = open(end+'/'+i, 'wb')
            line = file.read(65536)
            to_file.write(line)
            while(line):
                line = file.read(65536)
                to_file.write(line)
            file.close()
            to_file.close()
        except:
            os.access(end,3)
            os.chdir(end)
            try:
                os.mkdir(i)
            except:
                pass
            copy_dir(ini+'/'+i,end+'/'+i)
                
copy_dir('D:/PAQUETECOPIES','D:/n')