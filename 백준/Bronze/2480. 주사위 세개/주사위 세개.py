a, b, c = map(int, input().split())

if a == b and b == c:    # 다 같은 경우
  print(10000 + a * 1000)

elif a == b:             #  a, b 두개만 같은 경우
  print(1000 + a * 100)

elif b == c:             #  b, c 두개만 같은 경우
  print(1000 + b * 100)
  
elif c == a:             #  c, a 두개만 같은 경우
  print(1000 + c * 100)

else:
  print(max(a, b, c) * 100)