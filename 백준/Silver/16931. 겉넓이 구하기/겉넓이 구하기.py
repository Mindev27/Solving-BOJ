n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
result = n * m * 2
for row in arr:
  result += row[0] + row[-1] + sum(abs(row[i] - row[i + 1]) for i in range(len(row) - 1))
for col in zip(*arr):
  result += col[0] + col[-1] + sum(abs(col[i] - col[i + 1]) for i in range(len(col) - 1))
print(result)