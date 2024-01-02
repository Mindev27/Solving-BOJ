import sys
input = sys.stdin.readline

x, y, d, t = map(int, input().split())
dist = (x ** 2 + y ** 2) ** 0.5
if dist > d: ans = min(min(dist, t * (dist // d) + dist % d), t * (dist // d + 1))
else: ans = min(min(t + (d - dist), 2 * t), dist)
print(ans)