Tc = int(input())
for i in range(Tc):
  N = int(input())
  s, t = map(int, input().split())
  time = 0
  
  while N > 1:
    if N % 2 == 1:
      N -= 1
      time += s
      continue

    time += min(t, s * (N // 2))
    N //= 2
  print(time + s)
      