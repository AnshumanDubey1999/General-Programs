t = int(input())
while t > 0:
	n,k  = input().split()
	n = int(n)
	k = int(k)
	l = list(map(int, input().split()))
	l.sort()
	possible = True
	while possible:
		possible = False
		for i in range(len(l)-1):
			if l[i]>k:
				sum += k;
				l[i+1] -= l[i]-k
			else:
				sum += l[i]

	print(sum(l))
	t-=1

def abc(l, k):
	a = set()
	for i in range(len(l)):
		for j in range(len(l)):
			if i!=j and l[i]>k and l[j]>k:
				if(l[i]>l[j]):
					a.add((i,j))
				else:
					a.add((j,i))
	if(len(a) == 0):
		return sum(l)

	m = 0;
	for cords in a:
		nl = l.copy()
		nl[cords[0]] -= (nl[cords[1]]-k)
		nl[cords[1]] = k
		w = abc(nl,k)
		if w>m:
			m = w
	return m

t = int(input())
while t > 0:
	n,k  = input().split()
	n = int(n)
	k = int(k)
	l = list(map(int, input().split()))
	print(abc(l,k))
	t-=1


for test in range(int(input())):
    a,k=map(int,input().split())
    elem=list(map(int,input().split()))
    redu=[]
    sum1=0
    for i in elem:
        if (i>k):
            redu.append(i-k)
        else:
            sum1+=i
    siz=len(redu)
    if (siz == 0):
        print(sum1)
    elif (siz == 1):
        print(sum1 + k + redu[0])    
    else:
        redu.sort()
        greatest=redu[-1]
        redu=redu[:-1]
        siz=siz-1
        if (siz == 1):
            print(sum1 + 2*k + greatest - redu[-1] )
        else:
            sum2=(siz+1)*k + sum1
            rem=sum(redu)
            if (redu[-1] *2 <= rem):
                print((greatest- rem%2) +sum2)
            else:
                print((greatest-(redu[-1] *2 -rem)) + sum2)


#_____________________________________________________________________________________________________________________________________________________________

t = int(input())
while t > 0:
	s = input()
	if int(s)<10:
		print(s)
		t-=1
		continue
	if s[1] == '0':
		i = 1
		while i < len(s):
			if s[i] != '0':
				break
			i+=1
		print(s[i:])
		t-=1
		continue
	m = -1
	mi = -1
	for i in range(len(s)):
		if s[i] == '0' and m!=-1:
			break
		if int(s[i])>m:
			m = int(s[i])
			mi = i
	i = 0
	n = 0
	while i < len(s):
		if i == mi:
			i+=1
			continue
		n = n*10 + int(s[i])
		i+=1
	print(n)
	t-=1

def main():
	t = int(input())
	while t > 0:
		s = input()
		m = int(s)
		mx = m
		for i in range(len(s)):
			p = 10**i
			a = m%p + m//(p*10)*(p)
			if a <mx:
				mx = a
			print(a,mx)
		print(mx)
		t-=1


#______________________________________________________________________________________________________________________________________________________

def main():
	for test in range(int(input())):
	    a,k=map(int,input().split())
	    elem=input()
	    data = {}
	    pm = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71]
	    for i in 'abcdefghijklmnopqrst':
	    	data[i] = []

	    strings=[]
	    for i in range(k):
	        temp=input()
	        strings.append(temp)
	        for j in temp:
	        	data[j].append(i)
	    sol=[] 
	    cur=0
	    i = 0
	    for i in elem:
	        if(strings[cur].find(i)!=-1):
	            sol.append(cur+1)
	            continue
	   
	        
	        sol.append(data[i][0]+1)
	        cur=data[i][0]
	    print(*sol)




#__________________________________________________________________________________________________________________________________________________________

def main():
	for test in range(int(input())):
		trains = int(input())
		vals = []
		flag = True
		for i in range(trains):
			sim = 1
			l,r,v = map(int, input().split())
			for i in vals:
				if i[0]<r or i[1]<l:
					if i[2] == v:
						sim+=1
			if sim == 3:
				flag = False
			vals.append((l,r,v))
		print("YES" if flag else "NO")




#106.223.12.0