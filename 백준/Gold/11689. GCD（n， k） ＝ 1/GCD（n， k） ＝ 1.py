n = int(input())
answer = n

i = 2
while i * i <= n:
  if n % i == 0:
    answer -= answer / i;
    while n % i == 0:
      n /= i;
  i += 1

if n > 1: answer -= answer / n

print(int(answer))