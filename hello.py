def fact(n):
	if n<2:
		return 1
	return n*fact(n-1)

def main():
	t = int(input())
	while t>0:
		t-=1
		n = int(input())
		print(fact(n))

main()