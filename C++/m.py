f = open("test.txt","w")
st = ""
n = 1000
f.write(str(n)+"\n")
for i in range(n):
    st = st + " " + str(i+1)
st += '\n'
f.write(st)
f.write(st)
f.close()