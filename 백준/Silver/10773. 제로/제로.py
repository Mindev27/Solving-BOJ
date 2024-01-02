T = int(input())
a=[]

for i in range(T):
  num = int(input())

  if(num == 0):
    del a[-1]

  else:
    a.append(num)

print(sum(a))