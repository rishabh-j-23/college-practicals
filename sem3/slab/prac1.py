x = int(input("Number 1 : "))
y = int(input("Number 2 : "))
z = x + y
print("Sum : ",x + y)

# x and y values taken from previously code
if x > y:
    print(f"{x} is greater")
else:
    print(f"{y} is greater")


num = z
if num % 2 == 0:
    print(f"{num} is Even")
else:
    print(f"{num} is odd")

print("Before Swap : ",x, y)
temp = x
x = y
y = temp
print("After Swap : ",x, y)
