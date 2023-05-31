print("prac 4(i)")
list = [1123,243,5,4231,35,56,74,5,45]
print(list)
print("type : ",type(list))
print("list item at index 3 : ", list[3])
list.append(6437)
print("after appending 6437 : ", list)
list.remove(243)
print("after removing 243 : ", list)
print("length of list : ", len(list))

print()
print("prac 4(ii)")
tuple = (5,31,8,56,34,1,3,5,6,9,1)
print(tuple)
print("type : ", type(tuple))
print("length of tuple : ", len(tuple))

print()
print("prac 4(iii)")
m1 = [[1,2,3], [3,4,5], [5,6,7]]
m2 = [[10,20,30], [30,40,50], [50,60,70]]
row = []
res = []

for i in range(len(m1)):
    for j in range(len(m2)):
        row.append(m1[i][j] + m2[i][j])
    res.append(row)
    row = []

print("Matrix 1 : ", m1)
print("Matrix 2 : ", m2)
print("addition of two matrix : ", res)