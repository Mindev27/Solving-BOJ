import sys
score=[]
for i in range(9):    
    score.append(int(sys.stdin.readline()))

x=sorted(score)

num_list=[1,2,3,4,5,6,7,8,9]

i=0
while True:
    if score[i]>score[i+1]:
        score[i],score[i+1]=score[i+1],score[i]
        num_list[i],num_list[i+1]=num_list[i+1],num_list[i]
    i+=1
    if i>=8:
        i=0
    if x==score:
        break
print(score[8])
print(num_list[8])