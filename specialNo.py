import time

# def freq(n, k):
#     c = 0
#     while(n>0):
#         if(n%10 == k):
#             c+=1
#         n//=10
#     return c


# def isSpecial(n):
#     s = str(n)
#     for i in range(len(s)):
#         if(ord(s[i])-48 != freq(n,i)):
#             return False
#     return True



# def main():
#     for i in range(0,10000000000):
#         if isSpecial(i):
#             print(i)


# def rec(depth, num, freq):
#     # print('Depth: ', depth, num, freq)
#     if(depth==len(num)):
#         for i in freq:
#             if i != 0:
#                 return False
#         return True
#     initialFreq = freq[depth]
#     for i in range(initialFreq, depth):
#         # print('\tFirst Loop: ', i)
#         if freq[i]!=0:
#             num[depth] = i
#             freq[depth] = i - initialFreq
#             freq[i]-=1
#             if rec(depth+1, num, freq):
#                 return True
#             freq[i]+=1
#     if(depth!=freq[depth]):
#         num[depth]=depth
#         freq[depth] = depth - 1 - initialFreq
#         if rec(depth+1, num, freq):
#             return True
#     for i in range(depth+1,len(num)):
#         # print('\tSecond Loop: ', i)
#         num[depth] = i
#         freq[depth] = i - initialFreq
#         freq[i]+=1
#         if rec(depth+1, num, freq):
#             return True
#         freq[i]-=1
#     freq[depth] = initialFreq
#     return False

def rec(depth, num, freq):
    # print('Depth: ', depth, num, freq)
    if(depth==0):
        num[0]=freq[0];
        freq[0]=0;
        freq[num[0]]-=1;
        for i in freq:
            if i != 0:
                freq[0]=num[0]
                freq[num[0]]+=1
                return False
        return True
    initialFreq = freq[depth]
    for i in range(initialFreq, depth):
        # print('\tFirst Loop: ', i)
        num[depth] = i
        freq[depth] = i - initialFreq
        freq[i]+=1
        if rec(depth-1, num, freq):
            return True
        freq[i]-=1
        
    if(depth!=freq[depth]):
        num[depth]=depth
        freq[depth] = depth - 1 - initialFreq
        if rec(depth-1, num, freq):
            return True
    for i in range(depth+1,len(num)):
        # print('\tSecond Loop: ', i)
        if freq[i]!=0:
            num[depth] = i
            freq[depth] = i - initialFreq
            freq[i]-=1
            if rec(depth-1, num, freq):
                return True
            freq[i]+=1
        
    freq[depth] = initialFreq
    return False

    


def main():
    print("Enter the number of digits: ", end='')
    n = int(input())
    start = time.time()
    num = [0]*n
    freq = [0]*n
    # if rec(0,num,freq):
    if rec(n-1,num,freq):
        for i in num:
            print(i, end='')
        print()
    else:
        print("No such number exists.")
    end = time.time()
    print('Time Taken(seconds): ' ,(end-start))

main()








# 0
# 1210
# 2020
# 21200
# 3211000
# 42101000
# 521001000
# 6210001000