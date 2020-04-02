primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101]

def strToInt(s):
	n = 1
	for i in s:
		n *= primes[ord(i)-97]
	return n
db = {}
num = int(input())
for i in range(0, num):
	s = input()
	n = strToInt(s)
	if(db.get(n, False)):
		db[n].append(i)
		
	else:
		db[n] = [i]
	#print(db)

for key in db:
	print(db[key], end=",")