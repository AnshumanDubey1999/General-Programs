import math
import time

def nod(n):
	c = 0
	while n>0:
		n//=10
		c+=1
	return c

def isPrime(n):
	if n==2:
		return True
	if n<2 or n%2==0:
		return False
	for i in range(3,int(math.sqrt(n)+1),2):
		if n%i==0:
			return False
	return True

def getPrimes(n):
	isPrime = [True]*(n+1)

	p = 2
	while p*p <= n:
		if isPrime[p]:
			for i in range(p*p, n, p):
				isPrime[i] = False
		p +=1

	c = 0
	for i in range(n+1):
		if isPrime[i]:
			c+=1

	primes = [0]*c
	c = 0
	for i in range(n+1):
		if isPrime[i]:
			primes[c] = i
			c+=1

	return primes

def recursionLength(n):
	remainders = [0]*n;
	i = 0
	x = 1
	while True:
		remainders[x]=i
		x = (x*10)%n
		if x==0 or remainders[x]!=0:
			break
		i+=1
	#print(remainders)
	return 0 if x==0 else i - remainders[x]+1;

def sumPowNod(n):
	s=0
	x = nod(n)
	while n>0:
		s += (n%10)**5
		n//=10
	return s

def numFreq(n):
	freq = [0]*10
	n = str(n)
	for i in n:
		freq[ord(i)-48]+=1
	return freq

def isPan(freq):
	for i in freq:
		if i!=1 and i!=0:
			return False
	return True

def is9PanDigital(fs, strict = True):
	# print(fs)
	for i in range(1,10):
		s = 0
		for j in fs:
			s += j[i]
		if (strict and s!=1) or (not strict and s!=0 and s!=1):
			return False
	return True

def checkPanDigital(n, func, values):
	if len(values)==0:
		# print(n, func(3), func(10))
		if func(n):
			return n
		return 0

	curVal = values[:]
	curNum = n
	for i in values:
		curNum = n*10+i
		curVal.remove(i)
		x = checkPanDigital(curNum, func, curVal)
		if x!=0:
			return x
		curNum = n
		curVal = values[:]
	return 0



def getConcatinatedProducts(n):
	res = str(n)+str(n*2)
	if nod(n)==3:
		res += str(n*3)
	# print(res)
	if is9PanDigital([numFreq(res)]):
		return int(res)
	return 0


def hcf(a,b):
	if a==0:
		return b
	if b==0:
		return a
	if a==b:
		return a
	if a>b:
		return hcf(a-b,b)
	return hcf(a,b-a)

def isFractionalCancilation(a,b):
	if a%10==0 and b%10==0:
		return False
	div = hcf(a,b)
	x = 1
	y = 1
	if a%10 == b%10:
		x = a//10
		y = b//10
	elif a//10 == b%10:
		x = a%10
		y = b//10
	elif a%10 == b//10:
		x = a//10
		y = b%10
	elif a//10 == b//10:
		x = a%10
		y = b%10
	else:
		return False

	a = a//div
	b = b//div

	div = hcf(x,y)

	x = x//div
	y = y//div

	return x==a and y==b

def sumOfFactorialDigit(n, data = [1,1,2,6,24,120,720,5040,40320,362880]):
	s = 0
	while n!=0:
		s += data[n%10]
		n//=10
	return s


def isCircularPrime(n, primes):
	initial = n
	size = nod(n)-1
	n = (n%10)*(10**size)+n//10
	while n!=initial:
		if n not in primes:
			return False
		n = (n%10)*(10**size)+n//10
	return True

def isDoublePalindrome(n):
	a = str(n)
	b = a[::-1]
	if a==b:
		c = bin(n).replace('0b','')
		d = c[::-1]
		return c==d
	return False

def isTruncatedPrime(n, primes):
	x = n
	while x!=0:
		if x not in primes:
			return False
		x//=10

	x = nod(n)-1
	while x>=0:
		if n not in primes:
			return False
		n %= 10**x
		x-=1
	return True





def main():
	start = time.time()

	size = 9
	for i in range(9,1,-1):
		x = checkPanDigital(0, isPrime, [k for k in range(i,0,-1)])
		if x!=0:
			break
	print(x)

	
	

	end = time.time()
	print('Time Taken(seconds): ' ,(end-start))






main()