n = int(input())
a = input().split()
for i in range(n-1) :
	print(int(a[i]) + int(a[n-i-1]), end = ' ')
print(int(a[0]) + int(a[n-1]), end = '')        #For presentation Error