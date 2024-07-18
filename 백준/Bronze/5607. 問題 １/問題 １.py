n = int(input())
A = 0
B = 0

for i in range(n):
    a, b = map(int, input().split())
    if a == b:
        A += a
        B += b
    elif a > b:
        A += a + b
    else:
        B += a + b
print(f"{A} {B}")
