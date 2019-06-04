#!python3

def factorial(n:int)->int:
	"""
	Return n! - the factorial of n.

	>>> factorial(1)
	1
	>>> factorial(0)
	1
	>>> factorial(3)
	6
	
	"""	
	if n<=0:
		return 1
	elif n==1:
		return 1
	else:
		return n*factorial(n-1)


if __name__ == "__main__":
    import doctest
    (failures,tests) = doctest.testmod(report=True)
    print ("{} failures, {} tests".format(failures,tests))
