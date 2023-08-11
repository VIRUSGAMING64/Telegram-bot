
import ctypes as c
def p(data):
    print(data)
k32 = c.WinDLL("kernel32.dll",use_last_error=1)
hresult = k32.CreateFileW("mifile.txt",2032127,1,None,4,128,None)
p(hresult)