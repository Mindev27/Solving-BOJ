import math

x, y, c = map(float, input().split())

def solve(x, y, c):
    def tFunc(w):

        h1 = math.sqrt(x**2 - w**2)
        h2 = math.sqrt(y**2 - w**2)

        return (h1 * h2) / (h1 + h2) - c

    left, right = 0, min(x, y)
    while right - left > 1e-4:
        wMid = (left + right) / 2
        if tFunc(wMid) < 0:
            right = wMid
        else:
            left = wMid

    return (left + right) / 2

print(round(solve(x, y, c), 3))
