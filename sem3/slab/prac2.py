year = int(input("Enter a year: "))

if (year % 400 == 0) and (year % 100 == 0):
    print("{0} is a leap year".format(year))
elif (year % 4 ==0) and (year % 100 != 0):
    print("{0} is a leap year".format(year))
else:
    print("{0} is not a leap year".format(year))


x = int(input("Number 1 : "))
y = int(input("Number 2 : "))
z = int(input("Number 3 : "))

if x > y  and x > z:
    print(f"{x} is greatest of three")
elif y > z:
    print(f"{y} is greatest of three")
else: 
    print(f"{z} is greatest of three")
