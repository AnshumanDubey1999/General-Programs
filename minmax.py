
import random as rand

def fun1(a,b):
	while(a%b!=0):
		x = a%b
		a = b
		b = x
	return b

def fun2(a,b):
	if(a==0):
		return b
	return fun2(b%a, a)

def main():
	findings = 0
	loops = 0
	while(True):
		a = int(input())
		b = int(input())
		if a == -1 or b == -1:
			break
		c = fun1(a,b);
		d = fun2(a,b)
		print(a,b,c, (a*b)//c, d, (a*b)//d, sep="\t")
		

main()