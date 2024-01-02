from collections import deque

n, k, m = map(int, input().split())
queue = deque()
result = []

for i in range(1, n+1):
  queue.append(i)

cnt = 0

for i in range(n):
  
  queue.rotate(-k)
  result.append(queue[-1])
  queue.pop()
  
  cnt += 1
  
  if cnt == m:
    cnt = 0
    queue.reverse()
    


for i in result:
  print(i)