import math
import time

def nod(n):
	c = 0
	while n>0:
		n//=10
		c+=1
	return c
def sod(n):
	s = 0
	while n!=0:
		s+=n%10
		n//=10
	return s
def reverse(n):
	r = 0
	while n!=0:
		r = r*10 + n%10
		n//=10
	return r

def readToArray(path, splitter):
	f = open(path, "r")
	x = f.read().split(splitter)
	return x

def isSquare(n):
	return math.sqrt(n)==int(math.sqrt(n))

def powModded(b, e, l=10):
	p = 1
	for i in range(e):
		# print(p)
		p*=b
		p%=10**(l+2)
	return p%(10**l)

def combinations(arr, pos = 0):
	if pos == len(arr)-1:
		return [[arr[pos]], []]
	x = combinations(arr,pos+1)
	y = x[:]
	for i in x:
		y.append(i + [arr[pos]])
	# print(pos,arr,y)
	return y

def combine2(arr):
	a = []
	i = 0
	while i < len(arr)-1:
		j = i+1
		while j < len(arr):
			a.append(int(str(arr[i])+str(arr[j])))
			a.append(int(str(arr[j])+str(arr[i])))
			j+=1
		i+=1
	return a


def nCr(n,r,limit = -1):
	r = max(r,n-r)
	p = 1
	d = r
	for i in range(n,n-r,-1):
		p *=i
		while d>1 and p%d==0:
			p//=d
			d-=1
		if limit!=-1 and d == 1 and p>limit:
			return p
	return p

def replaceCharacters(s, indexes, char):
	c = list(s)
	for i in indexes:
		c[i] = char
	return ''.join(c)

def indexesOf(s, c):
	indexes = []
	for i in range(len(s)):
		if s[i] == c:
			indexes.append(i)
	return indexes

def printAscii(arr):
	for i in arr:
		if i >= 32:
			print(chr(i), end='')
	print()


def isPrime(n):
	if n==2:
		return True
	if n<2 or n%2==0:
		return False
	for i in range(3,int(math.sqrt(n)+1),2):
		if n%i==0:
			return False
	return True
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
def getPrimes(n):
	isPrime = getIsPrime(n)

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
def isCircularPrime(n, primes):
	initial = n
	size = nod(n)-1
	n = (n%10)*(10**size)+n//10
	while n!=initial:
		if n not in primes:
			return False
		n = (n%10)*(10**size)+n//10
	return True
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
def getPrimeFactors(n, repeat=False, dp={}):
	pf = set()
	if(n%2 == 0):
		pf.add(2)
		n//=2
		if dp.get(n) != None:
			return dp.get(n).union(pf)
	while(n%2==0):
		if repeat:
			pf.add(2)
		n//=2
	i = 3
	while n>1:
		if(n%i == 0):
			pf.add(i)
			n//=i
			if dp.get(n) != None:
				return dp.get(n).union(pf)
		while(n%i==0):
			if repeat:
				pf.add(i)
			n//=i
		i+=2

	return pf
def isPrimeConcatCompatible(arr, isPrime):
	i = 0
	while i < len(arr)-1:
		j = i+1
		while j < len(arr):
			x = int(str(arr[i])+str(arr[j]))
			y = int(str(arr[j])+str(arr[i]))
			if x>=len(isPrime) or y>=len(isPrime):
				return False
			if (not isPrime[x]) or (not isPrime[y]):
				return False
			j+=1
		i+=1
	return True


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
def checkPanDigital(n, func, values, ans):
	if len(values)==0:
		# print(n)
		if func(n) and n not in ans:
			ans.append(n)
		return ans

	curVal = values[:]
	curNum = n
	for i in values:
		curNum = n*10+i
		curVal.remove(i)
		ans = checkPanDigital(curNum, func, curVal, ans)
		curNum = n
		curVal = values[:]
	return ans
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

def isPalindrome(n):
	return n==reverse(n)

def isLychrelNumber(n):
	s = n + reverse(n)
	c = 1
	while c<=50:
		if isPalindrome(s):
			return False
		s += reverse(s)
		c+=1
	return True

def isDoublePalindrome(n):
	a = str(n)
	b = a[::-1]
	if a==b:
		c = bin(n).replace('0b','')
		d = c[::-1]
		return c==d
	return False


def toNum(s):
	n = 0
	for i in s:
		n += ord(i)-64
	return n

def triNum(n):
	return (n*(n+1))//2
def sqNum(n):
	return n*n
def pentaNum(n):
	return (n*(3*n-1))//2
def hexaNum(n):
	return (n*(2*n-1))
def heptaNum(n):
	return (n*(5*n-3))//2
def octaNum(n):
	return (n*(3*n-2))

def decryptXOR(s,k):
	ans = []
	x = 0
	while x < len(s):
		for i in k:
			ans.append(s[x]^ord(i))
			x+=1
			if x==len(s):
				break
	return ans

def asciiIsWord(arr):
	valid = [ord(i) for i in '!, ?.-&%$@+=:;_)(*|\\][}/<>{0123456789"\'']+[i for i in range(65,92)]+[i for i in range(97,123)]
	# printAscii(valid)
	for i in arr:
		if i not in valid:
			# print(i, chr(i))
			return False
	return True

def allValuesInRange(l, u, f):
	arr = []
	i = 0
	while f(i)<l:
		i+=1
	while f(i)<u:
		arr.append(f(i))
		i+=1
	return arr



def main():
	start = time.time()
	
	func = [triNum, sqNum,pentaNum, hexaNum, heptaNum, octaNum]
	tri =  allValuesInRange(1000,10000,triNum)
	sq =   allValuesInRange(1000,10000,sqNum)
	pen =  allValuesInRange(1000,10000,pentaNum)
	hexa = allValuesInRange(1000,10000,hexaNum)
	hept = allValuesInRange(1000,10000,heptaNum)
	octa = allValuesInRange(1000,10000,octaNum)

	for f in func:
		print(len(allValuesInRange(1000,10000,f)))








	end = time.time()
	print('Time Taken(seconds): ' ,(end-start))






main()
