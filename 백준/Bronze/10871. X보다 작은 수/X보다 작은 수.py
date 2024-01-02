import sys

n, x=map(int, sys.stdin.readline().split(" "))
a=list(map(int, sys.stdin.readline().split(" ")))
b=[]

for i in range(1,len(a)+1):
    if a[i-1] < x:
        b.append(a[i-1])
    
 
for i in range(1,len(b)+1):
    print(b[i-1], end=" ")