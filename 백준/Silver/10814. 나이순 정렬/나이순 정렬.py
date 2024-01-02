a = int(input())
member=[]

for i in range(a):
  
  old, name =input().split()
  member.append([int(old), name])

member.sort(key=lambda x:x[0])

for i in range(a):  
  
  print(member[i][0], member[i][1])  
