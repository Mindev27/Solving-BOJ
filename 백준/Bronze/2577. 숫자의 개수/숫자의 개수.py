import sys

import math

a=int(sys.stdin.readline())

b=int(sys.stdin.readline())

c=int(sys.stdin.readline())

n=a*b*c

num_list=[0,0,0,0,0,0,0,0,0,0]

i=n%10

while True:

    num_list[i]+=1

    n=math.floor(n/10)

    i=n%10

    if n<1:

        break

for i in range(10):

    print(num_list[i])