import sys 
n=int(sys.stdin.readline())
a=0

for i in range(n,0,-1):
    for k in range(a):
        print(" ",end="")
    for j in range(2*i-1,0,-1): 
        print("*",end="")
    print()
    a+=1
a=n-2
for i in range(2,n+1):
    for k in range(a):
            print(" ",end="")
    for j in range(1,2*i):
        print("*",end="")
    print()
    a-=1