import sys

new_score=[]

sum=0

n=int(sys.stdin.readline())

a=list(map(int, sys.stdin.readline().split()))

max_num=a[0]

for i in range(n):

    max_num=max(max_num,a[i])

for i in range(len(a)):

    new_score.append(a[i]/max_num*100)

for i in range(len(new_score)):

    sum+=new_score[i]

print(sum/len(new_score))

