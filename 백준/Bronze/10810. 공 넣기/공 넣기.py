n , m = map(int, input().split())

list = []

for r in range(0,200):
  list.append(0)

for q in range(0,m):
  
  i,j,k = map(int, input().split())

  for p in range(i, j+1):
    list[p] = k


for i in range(1, n+1):
  print(f"{list[i]}", end=" ")