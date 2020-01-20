import itertools

x = [1, 3, 7]

allPermutations = [p for p in itertools.product(x, repeat=4)]

for permutation in allPermutations:
	count1 = 0
	count3 = 0
	count7 = 0
	solution = 0
	for i in range (0, len(permutation)):
		solution += permutation[i] * (10 ** i)
		if permutation[i] == 1:
			count1 += 1
		elif permutation[i] == 3:
			count3 += 1
		elif permutation[i] == 7:
			count7 += 1

	if ((count1 == 2 and count3 == 1 and count7 == 1) or
		(count1 == 1 and count3 == 2 and count7 == 1) or
		(count1 == 1 and count3 == 1 and count7 == 2)):
	   for i in range (3, solution, 2):
	   		if solution % i == 0:
	   			break
	   if i+2 == solution:
	   	print (solution)	
		

