import tensorflow as tf
import numpy as np
import random as R
X = []
Y = []
for j in range(2):
    for i in range(10):
        for k in range(10):
            X.append([i,k,j])
            Y.append([(i) + (k) + j])
x_train = np.array(X)
y_train = np.array(Y)
arch=[]

for i in range(200):
    arch.append( tf.keras.layers.Dense(3, input_shape=(3,),activation="elu"))

arch.append(tf.keras.layers.Dense(1, activation='elu'))  # Output layer

model = tf.keras.models.Sequential(arch)
model.compile(loss="mean_squared_error",metrics=['accuracy'])

model.fit(np.array(X),np.array(Y),epochs=100)
loss,acu = model.evaluate(np.array(X),np.array(Y))
print(loss)
print(model.predict(np.array(X)))