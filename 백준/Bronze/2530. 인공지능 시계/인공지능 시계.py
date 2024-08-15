H, M, S = map(int, input().split())
S = S + int(input()) 

M = M + int(S/60)
H = H + int(M/60)

H = H % 24
M = M % 60
S = S % 60

print("%s %s %s" %(H, M, S))