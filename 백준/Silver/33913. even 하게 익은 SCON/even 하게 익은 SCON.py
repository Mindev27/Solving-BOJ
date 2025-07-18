MOD = 10**9+7
div2 = (MOD+1)//2 # 나누기2

N = int(input().strip())
a = pow(26, N, MOD)
b = pow(22, N, MOD)
print((a + b) * div2 % MOD)