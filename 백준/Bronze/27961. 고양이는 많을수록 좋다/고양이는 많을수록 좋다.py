n = int(input())
if n == 0: print(0)
elif n == 1: print(1)
else:
  cnt = 1
  cat = 1
  while(cat < n):
    cat *= 2
    cnt += 1
  print(cnt)
