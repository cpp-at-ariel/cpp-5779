#!python3

	import cppyy
	cppyy.include("functions.hpp")

print("Call a C++ function that expects a vector:")
print(cppyy.gbl.sum([1,2,3,4,5,6,7,8,9,10]))
print(cppyy.gbl.sum(range(1,11)))
print(cppyy.gbl.sum([[1,2,3],[4,5,6],[7,8,9,10]]))
# print(cppyy.gbl.sum(set(range(1,11))))  # error
# print(cppyy.gbl.sum(frozenset(range(1,11)))) # error
# print(cppyy.gbl.sum({55:1,66:2,77:3})) # error
# print(cppyy.gbl.sumset(set(range(1,11)))) # error
print(cppyy.gbl.sumset(list(range(1,11))))

print(cppyy.gbl.summap({55:1,66:2,77:3}))
print(cppyy.gbl.summap(list({55:1,66:2,77:3})))

print(cppyy.gbl.sum.__doc__)