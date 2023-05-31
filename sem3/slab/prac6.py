def to_decimal(num, base: int):
    global bin
    bin= ''
    if base == 2:
        num = int(num)
        decimal, i = 0, 0
        while(num != 0):
            dec = num % 10
            decimal = decimal + dec * pow(2, i)
            num = num//10
            i += 1
        return int(decimal)
    
    if base == 8:

        num = n
        decimal = 0
        base = 1
        temp = num
        while (temp):
            last_digit = temp % 10
            temp = int(temp / 10)
            decimal += last_digit * base
            base = base * 8

        return decimal

    if base == 16:
        table = {'0': 0, '1' : 1, '2' : 2, '3' : 3, '4' : 4, '5' : 5, '6' : 6, '7' : 7, '8' : 8, '9' : 9, 'A' : 10 , 'B' : 11, 'C' : 12, 'D' : 13, 'E' : 14, 'F' : 15}  
        hexadecimal_string = num 
        decimal = 0  
        
        length = len(hexadecimal_string) -1  
        
        for digit in hexadecimal_string:  
            decimal += table[digit]*16**length  
            length -= 1  
        
        return decimal

    return -1

bin = ''
def to_binary(num, base = None):
    global bin
    if base != None:
        num = to_decimal(num, base)

    if num >= 1:
        to_binary(num // 2)

    bin = bin + f"{num%2}"

    return int(bin)

def to_octal(num, base = None):

    if base != None:
        num = to_decimal(num, base)
    octal = 0
    count = 1
    deci = num
    
    while (deci != 0):
        remainder = deci % 8
        octal += remainder * count    
        count = count * 10
        deci = deci // 8
    
    return octal

def to_hexadecimal(num, base = None):
    if base != None:
        num = to_decimal(num, base)
    table = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    hexadecimal = ''
    while(num > 0):
        remainder = num % 16
        hexadecimal = table[remainder] + hexadecimal
        num = num // 16
 
    return str(hexadecimal)

print(to_binary(5))
print(to_octal(10))
print(to_hexadecimal(11))
print(to_decimal('10', 16))
print(to_binary('10', base=16))
print(to_octal('0101', base=2))