X = [1,3,4,2]
Y = [2,6,8,4]

b = 0
c = 0
d = 0
Lrate =  0.00001

def f(x):
    global  b, c, d
    return  b*x**2 + c*x + d

def update(err,x,pred):
    global a, b, c, d,Lrate
    b = b - err * Lrate * x ** 2
    c = c - err * Lrate * x
    d = d - err * Lrate 

def Learn():
    global X,Y
    for n in range(10**6):
        for i in range(len(X)):
            pred = f(X[i])
            err  = pred - Y[i]
            update(err,X[i],pred)
Learn()
n = int(input('number: '))
print(f(n))
