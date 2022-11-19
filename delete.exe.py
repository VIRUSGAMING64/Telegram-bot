import os

def dfs(path):
    try:
        if(path.endswith('.exe')):
            os.remove(path)
            return
    except:
        return
    print(path)
    try:
        os.access(path,3)
        os.chdir(path)
        l = os.listdir()
    except:
        return
    for i in l:
        dfs(path+'\\' + i)
            
path = os.getcwd()
i = input('delete all .exe in '+path+' ?  Y/N  > ')
if(i == 'Y' or i == 'y'):
    dfs(path)
