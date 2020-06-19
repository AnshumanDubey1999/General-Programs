size = int(input())
matrix = []

for i in range(size):                          #input
	rows = input().split()
	for j in range(size):
		rows[j] = int(rows[j])
	matrix.append(rows)

for i in range(size):                         #removal
	for j in range(size):
		if(i>j):
			matrix[i][j] = 0


for i in range(size):                         #print
	for j in range(size):
		print(matrix[i][j], end = " " if j < (size-1) else "")
	if(i < (size-1)):
		print()

