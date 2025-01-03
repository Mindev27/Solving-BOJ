n,b=map(int,input().split());r=''
while n:r="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n%b]+r;n//=b
print(r)