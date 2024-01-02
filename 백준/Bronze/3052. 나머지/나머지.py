import sys

n=[]

k=0

a=int(sys.stdin.readline())%42

n.append(a)

for i in range(9):

    a=int(sys.stdin.readline())%42

    for j in range(len(n)):

        if n[j]!=a:

            k+=1

        if k==len(n):

            n.append(a)

    k=0

print(len(n))