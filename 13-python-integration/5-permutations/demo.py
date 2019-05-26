import itertools

print("Permutations or range:")
for p in itertools.permutations(range(1,5)):
	print(p)

print("Permutations or string:")
for p in itertools.permutations("abcd"):
	print("".join(p))

