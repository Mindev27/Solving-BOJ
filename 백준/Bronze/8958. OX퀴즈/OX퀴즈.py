import sys

n=int(sys.stdin.readline())

for i in range(n):

    i=0

    total=0

    a=list(map(str,sys.stdin.readline()))

    

    for j in range(len(a)):

        if a[j]=="O":

            i+=1

            total+=i

        elif a[j]=="X":

            i=0

        

    print(total)

    