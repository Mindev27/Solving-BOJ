a=[]
b=[]
c=0
m,n=map(int,input().split())

for i in range(m):
    i=list(map(int,input().split()))
    a.append(i)
  
for i in range(m):
    i=list(map(int,input().split()))
    b.append(i)

for i in range(m):
    for j in range(n):
        print(a[i][j] + b[i][j],end=(' '),sep=(' '))
    print()