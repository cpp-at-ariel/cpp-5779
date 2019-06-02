#!python3



import cppyy
cppyy.include("functions.hpp")

print("Call a C++ function that expects a std::vector:")
print(cppyy.gbl.sum([1,2,3,4,5,6,7,8,9,10]))
print(cppyy.gbl.sum(range(1,11)))
print(cppyy.gbl.sum([[1,2,3],[4,5,6],[7,8,9,10]]))
print(cppyy.gbl.sum.__doc__)


print("\nCall a C++ function that expects a std::set:")
# This returns a compilation error:
# print(cppyy.gbl.sumset(set(range(1,11))))

# We have to explicitly create a C++ set (not a Python set).
# See https://stackoverflow.com/a/56350681/827927
cppset = cppyy.gbl.std.set[int]()
for i in range(1,11):
	cppset.insert(i)
print(cppyy.gbl.sumset(cppset)) 
print(cppyy.gbl.sumset.__doc__)

#print("\nCall a C++ function that expects a std::map:")
#print(cppyy.gbl.sumset(list(range(1,11))))
#print(cppyy.gbl.summap({55:1,66:2,77:3}))
#print(cppyy.gbl.summap(list({55:1,66:2,77:3})))

