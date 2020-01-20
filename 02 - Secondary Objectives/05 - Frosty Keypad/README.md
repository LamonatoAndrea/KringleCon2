# 2. Secondary Objectives
## 2.6. Frosty Keypad
### 2.6.1. Description
Speaking with Tangle Coalbox:
>Hey kid, it's me, Tangle Coalbox. I'm sleuthing again, and I could use your help. Ya see, this here number lock's been popped by someone. I think I know who, but it'd sure be great if you could open this up for me. I've got a few clues for you.
> 1. One digit is repeated once.
> 2. The code is a prime number.
> 3. You can probably tell by looking at the keypad which buttons are used.

Frosty Keypad appearance:
![Frosty Keypad apperance](https://github.com/LamonatoAndrea/KringleCon2/blob/master/02%20-%20Secondary%20Objectives/05%20-%20Frosty%20Keypad/frosty%20keypad.png)

### 2.6.2. Solution
Third hint from discussion above includes only digits 1, 3 and 7. Considering that one is repeated twice, it means the code is made up of 4 digits in total.

To find out the code, I wrote a small python script to calculate all permutations with repetition of four characters over the alphabet {1, 3, 7} matching all hints received. This allow to have below 5 potential solutions:
* 7331
* 3371
* 1733
* 1373
* 3137

Code 7331 unlocked the dorm’s door.
### 2.6.3. Afterwords
Speaking again with Tangle Coalbox:
>Yep, that's it. Thanks for the assist, gumshoe. Hey, if you think you can help with another problem, Prof. Banas could use a hand too. Head west to the other side of the quad into Hermey Hall and find him in the Laboratory.
### 2.6.4. Attachments
#### 2.6.4.1. solveme.py
```python
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
```