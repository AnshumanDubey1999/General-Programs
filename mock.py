def getIsPrime(n):
	isPrime = [True]*(n+1)
	isPrime[0] = isPrime[1] = False
	p = 2
	while p*p <= n:
		if isPrime[p]:
			for i in range(p*p, n, p):
				isPrime[i] = False
		p +=1

	return isPrime

def combine2(arr):
	a = set()
	i = 0
	while i < len(arr)-1:
		j = i+1
		while j < len(arr):
			a.add(int(str(arr[i])+str(arr[j])))
			a.add(int(str(arr[j])+str(arr[i])))
			j+=1
		i+=1
	return a

isPrime = getIsPrime(10000)

n1, n2 = input().split()
n1 = int(n1)
n2 = int(n2)

p1 = list(filter(lambda i: isPrime[i], (i for i in range(n1,n2+1))))
t = combine2(p1)
p2 = set(filter(lambda i: isPrime[i], t))
l = len(p2)-2
a = min(p2)
b = max(p2)
print(p1,p2,l,a,b)
while l > 0:
	c = a+b
	a = b
	b = c
	l-=1
print(b)



