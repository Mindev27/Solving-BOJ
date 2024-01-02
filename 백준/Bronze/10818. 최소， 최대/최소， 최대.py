import sys
a=[]
n=int(sys.stdin.readline())
a=list(map(int, sys.stdin.readline().split()))

x=sorted(a)

print(x[0],x[n-1])