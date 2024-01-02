import sys
import math

n=int(sys.stdin.readline())
a=0
b=0
c=0
cnt=0


while True:
    if cnt == 0:
        c=n
    a=math.floor(c/10)
    b=c%10
    
    if a+b>=10:
        c=10*b+a+b-10
    else:
        c=10*b+a+b
    cnt+=1
    if n==c:
        break

print(cnt)