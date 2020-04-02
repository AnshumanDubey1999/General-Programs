word = input()
upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
lowerCase = "abcdefghijklmnopqrstuvwxyz"
lowerCounter = 0
upperCounter = 0
for i in word:
	if (i in upperCase):
		upperCounter += 1
	elif(i in lowerCase):
		lowerCounter += 1
print(upperCounter, lowerCounter, end = "")