n = int(input())
a = 2;
for i in range(n):
	a += a - 1;
print(a**2)