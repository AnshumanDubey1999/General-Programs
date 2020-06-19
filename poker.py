def value(cards):
	suits = {}
	nums = {}
	arrangement = '023456789TJQKA'
	for card in cards:
		if suits.get(card[1]) == None:
			suits[card[1]] = 1
		else:
			suits[card[1]]+=1

		if nums.get(card[0]) == None:
			nums[card[0]] = 1
		else:
			nums[card[0]]+=1

	l = list(i for i in nums)
	indexes = list(map(lambda i: arrangement.index(i), (i for i in l)))
	indexes.sort()
	stCheck = [indexes[0]+i for i in range(5)]
	print('Indexes:',indexes)
	s = sum(indexes)
	
	if len(suits)==1:
		#royal Flush
		if nums.get('T')==1 and nums.get('J')==1 and nums.get('Q')==1 and nums.get('K')==1 and nums.get('A')==1:
			print('Is Royal Flush')
			return 10**18

		#straight Flush
		if indexes==stCheck:
			print('Is Straight Flush')
			return (10**16)*indexes[-1]

		#Flush
		print('Is Flush')
		return (10**10)*indexes[-1] + (10**8)*indexes[-2] + (10**6)*indexes[-3] + (10**4)*indexes[-4] + (10**2)*indexes[-5]

	
	if len(nums)==2:
		#four of a kind
		if nums[l[0]]==4:
			print('Is Four of a kind:',l[0])
			return (10**14)*arrangement.index(l[0])
		if nums[l[1]]==4:
			print('Is Four of a kind:',l[1])
			return (10**14)*arrangement.index(l[1])

		#full House
		print('Is Full House')
		if nums[l[0]]==3:
			return (10**12)*arrangement.index(l[0])
		return (10**12)*arrangement.index(l[1])


	#Straight
	if indexes == stCheck:
		print('Is Straight')
		return indexes[-1]

	if len(nums) == 3:
		flag = -1
		for i in nums:
			if nums[i]==3:
				flag = i

		if flag!= -1:          #Three of a kind
			print('Is Three of a kind')
			return arrangement.index(flag)*(10**-2)

		else:					#2 pairs
			a = b = c = 0
			if nums[l[0]]==1:
				a = max(arrangement.index(l[1]), arrangement.index(l[2]))
				b = min(arrangement.index(l[1]), arrangement.index(l[2]))
				c = arrangement.index(l[0])
			elif nums[l[1]]==1:
				a = max(arrangement.index(l[0]), arrangement.index(l[2]))
				b = min(arrangement.index(l[0]), arrangement.index(l[2]))
				c = arrangement.index(l[1])
			elif nums[l[2]]==1:
				a = max(arrangement.index(l[1]), arrangement.index(l[0]))
				b = min(arrangement.index(l[1]), arrangement.index(l[0]))
				c = arrangement.index(l[2])
			print('Is Pair of 2')
			return a*(10**-4)+b*(10**-6)+c*(10**-8)

	if len(nums)==4:				#1 pair
		flag = -1
		for i in nums:
			if nums[i]==2:
				flag = i

		l.remove(flag)
		indexes = list(map(lambda i: arrangement.index(i), (i for i in l)))
		indexes.sort()
		score = 0
		for i in range(-12,-17,-2):
			score += (10**i)*indexes[-((-i-12)//2 + 1)]
		score += (10**-10)*arrangement.index(flag)
		print('IS a pair')
		return score

	score = 0
	for i in range(-18,-27,-2):
		score += (10**i)*indexes[-((-i-18)//2 + 1)]
	return score



def readToArray(path, splitter=' '):
	f = open(path, "r")
	x = f.read().split(splitter)
	return x

# def main():
# 	games = readToArray('p054_poker.txt','\n')
# 	c = 0
# 	i = 1
# 	for game in games:
# 		print('-'*100)
# 		cards = game.split()
# 		print(i,cards[:5],cards[5:])
# 		print('-'*100)
# 		i+=1
# 		s1 = value(cards[:5])
# 		s2 = value(cards[5:])
# 		if s1 > s2:
# 			print('player 1 won')
# 			c += 1
# 		print('-'*100)
# 	print('Times player 1 won =', c)

def main():
	i = 1
	while True:
		print('Enter 10 cards:')
		cards = input().split()
		print(i,cards[:5],cards[5:])
		print('-'*100)
		i+=1
		s1 = value(cards[:5])
		s2 = value(cards[5:])
		print(s1,s2)
		if s1 > s2:
			print('										Player 1 Won')
		else:
			print('										Player 2 Won')
		print('-'*100)

main()


#Royal Flush
#Straight Flush
#Four of A kind
#Full House
#Flush   -> same suit
#Straight -> conswqutive values
#Three of a kind
#2 pairs
#1 pair
#Highest ranker



