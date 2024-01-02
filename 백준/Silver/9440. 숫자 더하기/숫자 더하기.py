import sys
input = sys.stdin.readline

while True:
  zero_cnt = 0
  mylist = list(map(int, input().split()))
  newlist = []

  if(len(mylist) == 1): break
  
  del mylist[0]

  for i in range(len(mylist)):
    if mylist[i] == 0:
      zero_cnt += 1
    else:
      newlist.append(mylist[i])

  newlist = sorted(newlist)


  for i in range(zero_cnt):
    newlist.insert(2, 0)

  A = int("".join(list(map(str,newlist[0::2]))))
  B = int("".join(list(map(str,newlist[1::2]))))

  print(A+B)
  