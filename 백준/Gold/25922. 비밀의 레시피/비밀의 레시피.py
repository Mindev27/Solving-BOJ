import sys

N = int(sys.stdin.readline().strip())

B = 10**9
print("? 1000000000")
sys.stdout.flush()

v = int(sys.stdin.readline().strip())

ans = []
for _ in range(N + 1):
    ans.append(v % B)
    v //= B
print("! " + " ".join(map(str, ans)))
sys.stdout.flush()
