N = int(input())
c = list(map(float, input().split()))

total_volume = sum(x ** 3 for x in c)
result = total_volume ** (1 / 3)

print(f"{result:.9f}")
