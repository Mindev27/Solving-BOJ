def solution():
    n = int(input())
    s = input()
    cnt = 0
    for i in range(len(s)):
        if s[i] == 'C':
            cnt += 1
    print(cnt // (n - cnt + 1) + (1 if cnt % (n - cnt + 1) != 0 else 0))

solution()
