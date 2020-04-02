past = {0:1, 1:1, 2:2, 4:3}
max = 3
maxID = 4

def isnt1(num, level, counter):
	if(num < 2):
		return
	if(num in past):
		counter = level + past[num]
		return counter
	if(num%2 == 0):
		counter = isnt1(int(num/2), level+1, 0)
	else:
		counter = isnt1(3*num + 1, level + 1, 0)
	past[num] = counter - level
	return counter

for i in range(2,10000000):
	count = isnt1(i, 0, 0)
	past[i] = count
	if(count > max):
		maxID = i
		max = count
sorted(past.values())
#print(past)
print(maxID, " : ", max)