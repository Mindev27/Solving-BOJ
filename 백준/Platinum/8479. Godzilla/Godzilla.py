N, M = map(int, input().split())
a = list(map(int, input().split()))

a.sort(reverse=True)

ans = 0
for i in range(N):
    if a[i] - i > 0:
        ans += a[i] - i

print(ans)
