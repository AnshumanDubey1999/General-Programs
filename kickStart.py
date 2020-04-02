t = int(input())

while t>0:
	a = list(map(int, input().split()))
	sum = 0
	for i in a:
		sum+=i
	mean = sum/len(a)
	temp = 0
	for i in a:
		temp += ((i-mean)**2)
		print(temp)
	sd = (temp/len(a))**0.5
	print(mean, sd, temp)


	t-=1