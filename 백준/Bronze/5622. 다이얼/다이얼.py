import sys

word=list(sys.stdin.readline())

cnt=0

for str in word:

    if str in ["A","B","C"]:

        cnt+=3  

    if str in ["D","E","F"]:

        cnt+=4   

    if str in ["G","H","I"]:

        cnt+=5

    if str in ["J","K","L"]:

        cnt+=6

    if str in ["M","N","O"]:

        cnt+=7

    if str in ["P","Q","R","S"]:

        cnt+=8        

    if str in ["T","U","V"]:

        cnt+=9

    if str in ["W","X","Y","Z"]:

        cnt+=10

print(cnt)