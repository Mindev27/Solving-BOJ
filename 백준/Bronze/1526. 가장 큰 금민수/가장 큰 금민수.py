n = int(input())
while True:
  if all(ch in ['4', '7'] for ch in str(n)): print(n); break;
  else: n -= 1
