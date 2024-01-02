import sys
word=sys.stdin.readline()
alpha=[]


for j in range(26):
     alpha.append(word.count(chr(65+j))+ word.count(chr(97+j)))

max_num=alpha[0]
for i in range(len(alpha)):
    if alpha[i]>=max_num:
        max_num=alpha[i]

k=0
for i in range(len(alpha)):
   if alpha[i]==max_num:
       k+=1
if k==1:
    print(chr(int(alpha.index(max_num))+65))
else:
    print("?")