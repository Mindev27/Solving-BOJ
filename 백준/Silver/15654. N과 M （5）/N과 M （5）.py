from itertools import permutations

a, b = map(int,input().split())
arr = list(map(int, input().split()))
arr.sort()

for i in permutations(arr, b):
  print(*i)