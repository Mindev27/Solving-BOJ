MOD = 1000000000
N = int(input())
dp = [0 for i in range(N + 10)]

dp[1] = 0
dp[2] = 1

for i in range(3, N + 1):
  dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])
  dp[i] %= MOD

print(dp[N])