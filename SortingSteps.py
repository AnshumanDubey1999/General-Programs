# def push(array, position):
# 	temp = array[position]                                           #Storing the number to be pushed in temporary variable
# 	for i in range(position, len(array)-1):       
# 		array[i] = array[i+1]                                        #Moving all the numbers after array[i] one step back
# 	array[size-1] = temp                                             #Pasting the original array[i] to the last place

# a = input().split()
# array = []
# for i in a:
# 	array.append(int(i))                                             #Taking input and putting it in an int array
# sortedArray = array.copy()
# sortedArray.sort()                                                   #Sorting the copy of array

# size = len(array)                                                    #Storing the size of array
# counter = 0  
# i = 0                                                                #Loop Variable
# while(i < size-1):
# 	if(array.index(sortedArray[i])>array.index(sortedArray[i+1])):   #If the 2 consequtive array elements of sorted array are not one after the other in original array    
# 		push(array, array.index(sortedArray[i+1]))                   #Send the 2nd element of the 2 consequtive elements to the last position
# 		counter += 1
# 	else:
# 		i += 1                                                       #Increase only when pushing not possible
# print(counter, end = "")
import sys,copy
Br=input().split(" ")
for i in range(len(Br)):
    Br[i]=int(Br[i])
Ar=copy.deepcopy(Br)
Ar.sort()
c=j=0
for i in range(len(Br)):
    if(Ar[j]==Br[i]):
        c+=1
        j+=1
print((len(Ar)-c),end="")