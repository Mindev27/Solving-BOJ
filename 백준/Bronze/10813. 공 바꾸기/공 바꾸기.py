n , m = map(int, input().split())

list = []

for r in range(0,101):
  list.append(r)

for q in range(0,m):
  
  i,j = map(int, input().split())

  list[i], list[j] = list[j],list[i]

for i in range(1, n+1):
  print(f"{list[i]}", end=" ")