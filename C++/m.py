import tensorflow as tf
import numpy as np
import random
import time


model = tf.keras.Sequential([
        tf.keras.layers.Dense(2, input_shape=(2,)),
        tf.keras.layers.Dense(2, activation='sigmoid'),
        tf.keras.layers.Dense(2, activation='sigmoid'),
        tf.keras.layers.Dense(2, activation='sigmoid'),
        tf.keras.layers.Dense(2, activation='sigmoid'),
        tf.keras.layers.Dense(1, activation='sigmoid'),
    ])

model.compile(optimizer='adam', loss='binary_crossentropy')

X = []
for i in range(1550):
    X.append([0,1])
    X.append([0,0])
    X.append([1,1])
    X.append([1,0])
Y = []
for i in range(1550):
    Y.append([1])
    Y.append([0])
    Y.append([0])
    Y.append([1])

# este es el dns de la wifi 

model.fit(np.array(X),np.array(Y),epochs=20,verbose=1)
while 1:
    a = int(input())
    b = int(input())
    x = 0
    for i in range(30):
        t = []
        if(a & (1 << i)):
            t.append(1)
        else:
            t.append(0)
        if(b & (1 << i)):
            t.append(1)
        else:
            t.append(0)
        d = model.predict(np.array([t]),verbose=0).round()
        if(d[0][0] == 1):
            x = x | (1 << i)
    print(x)