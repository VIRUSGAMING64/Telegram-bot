f2 = open('d:/new.txt',"w")
f = open('C:\\Users\\virus\\OneDrive\\Desktop\\Nuevo Text Document.txt',"r")
data = f.readline()
while data:
    s = ''
    for i in data:
        if i == "â" or i == '^' or i == '-':
            s += '$'
        else:
            s += i
    f2.writelines(data)
    data = f.readline()
f2.close()
f.close()