a2, a1, a0 = map(int, input().split())
c = int(input())
n0 = int(input())

#f(n) - g(n)과 x축으로 생각하기
a2 -= c

if a2 < 0: # 최고차항 음수면 불가능
  print(0)

else:
  dn = 2 * a2 * n0 + a1 # 미분한 값
  D = a1 * a1 - 4 * a2 * a0 # 판별식 값

  if dn < 0: # n0에서 기울기가 음수일때
    if D <= 0:
      print(1)
    else:
      print(0)
      
  else: # n0에서 기울기가 0이거나 양수일때
    if a2 * n0 * n0 + a1 * n0 + a0 >= 0:
      print(1)
    else:
      print(0)
    
  
