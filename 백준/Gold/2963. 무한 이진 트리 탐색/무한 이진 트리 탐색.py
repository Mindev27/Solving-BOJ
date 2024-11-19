def solve():
    s = input().strip()
    ans = 1
    star = 1
    for c in s:
        if c == 'L':
            ans *= 2
        elif c == 'R':
            ans = ans * 2 + star
        elif c == 'P':
            continue
        else:  # '*'
            ans = ans * 5 + star
            star *= 3

    print(ans)


if __name__ == "__main__":
    solve()
