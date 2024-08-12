N=int(input())
a,b,c,d,e,f=map(int,input().split())
T,P= map(int, input().split())

ans=6+(a-1)//T+(b-1)//T+(c-1)//T+(d-1)//T+(e-1)//T+(f-1)//T
print(ans)
x=N//P
y=N%P
print(f'{x} {y}')