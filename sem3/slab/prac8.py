import numpy as np 
from numpy import version

print("i")
list = [2,3,54,3,75,8,67,45,63,45]
listarr = np.array(list)
print(listarr)
tuple = (12,34,4,53,64,76,46,52,34,325)
tuplearr = np.array(tuple)
print(tuplearr)
print(type(tuplearr))
print(version.full_version)
print()

print("ii")
m = np.zeros(shape=(3, 3))
print(m)
m = np.ones(shape=(2, 2))
print(m)
print()

print("iii")
arr2d = np.array([[1,24, 23], [24,32,34], [42,1,2]])
for i in range(3):
    for j in range(3):
        print(arr2d[i][j], end=" ")
    print()
print()

print("iv")
m = np.concatenate([[23,42,342], [67,5,4]],  axis = 0)
print(m)
print()

print("v")
m1 = [12,33,5,356,23,1,3]
m2 = [11,23,5,356,23,1,3]
m = np.add(m1, m2) 
print(m)
m3 = np.multiply(m1, m2)
print(m3)
m4 = np.transpose(m1)
print(m4)