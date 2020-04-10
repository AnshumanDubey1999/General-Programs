file = open("test.txt", "r")
f1 = file.readlines()
fileLine = 1
for testCase in range(int(f1[0])):
    n=int(f1[fileLine])
    fileLine+=1
    q=list(map(int,f1[fileLine].split()))
    fileLine+=1
    n = len(q)
    cnt=0
    l=[]
    for i in range(n):
        if(q[i]%2==1) :
            l.append(1)
        elif(q[i]%4==0):
            l.append(4)
        else:
            l.append(2)
    cn1=0
    cn2=0
    cnt=0
    for i in range(0,n):
        if(l[i]==1):
            cn1+=1
        elif(l[i]==2 and cn2==0):
            cnt+=int((cn1*(cn1+1))/2)
            #print(int((cn1*(cn1+1))/2))
            cn2=cn1+1
            cn1=0
        elif(l[i]==2 and cn2>0):
            cnt+=int((cn1*(cn1+1))/2)
            #print(int((cn1*(cn1+1))/2))
            cn2+=cn1
            cnt-=int((cn2*(cn2+1))/2)
            cnt+=int((cn1*(cn1+1))/2)
            #cnt-=int(((cn1+1)*(cn1+2))/2)
            cn2=cn1+1
            cn1=0
        if(l[i]==4 or i==n-1 ):
            cnt+=int((cn1*(cn1+1))/2)
            cn2+=cn1
            cnt-=int((cn2*(cn2+1))/2)
            cn1=0
            cn2=0
    ans=((n*(n+1))/2)+cnt
    print(int(ans))