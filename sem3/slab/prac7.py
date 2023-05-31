def gcd( a, b):  
    if a > b:
        temp = b  
    else:  
        temp = a  
    for i in range(1, temp + 1):  
        if (( a % i == 0) and (b % i == 0 )):  
            gcd = i  
    return gcd

def lcm(x, y):  
    if x > y:  
        greater = x  
    else:  
        greater = y  
    while(True):  
        if((greater % x == 0) and (greater % y == 0)):  
            lcm = greater
            break  
        greater += 1  
    return lcm    

def is_coprime(x, y):
    return gcd(x, y) == 1

print(gcd(10, 15))
print(lcm(10, 15))
print(is_coprime(10, 15))