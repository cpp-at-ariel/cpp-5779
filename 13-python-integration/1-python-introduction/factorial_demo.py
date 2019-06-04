#!python3

import factorial

def test(x:int, y:int)->tuple:
	return (x-y,x+y)


print(factorial.factorial(5))
#print(test(y="abc",x="xyz"))
print(test(5,7))
# print(factorial.factorial("abc"))
