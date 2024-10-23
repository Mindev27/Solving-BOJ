N = int(input())
i = 10
while N >= i:
    N = (N + i // 2) // i * i
    i *= 10
print(N)
