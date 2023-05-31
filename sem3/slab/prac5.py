print("prac 5(i)")
set = {12,3,12,4,34,45,56,47,34,123,123}
print(set)
print("type : ", type(set))
print("length of set : ", len(set))
set.add(80)
print("after adding 80 : ", set)
set.remove(34)
print("after removing 34 : ",set)
set2 = {12,4,8,5,467,6,45,34,45,7}
print(set | set2)
print(set & set2)

print()
print("prac 5(ii)")
dict = {56: "Rishabh", 57: "Joe", 58: "Chandler", 59: "Monica"}
print(dict)
print("type : ", type(dict))
print("name of roll no 58 : ", dict.get(58))
dict.pop(57)
print("after removing : ", dict)
print("length : ", len(dict))
dict[58] = "Jason"
print("after updating : ", dict)
