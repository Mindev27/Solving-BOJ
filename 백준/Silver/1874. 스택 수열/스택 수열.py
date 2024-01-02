n = int(input())

stack = []
command = []
find = True

cnt = 1
for i in range(n):
  
  key = int(input())

  while (cnt <= key):
    stack.append(cnt)
    command.append("+")
    cnt += 1

  if (stack[-1] == key):
    stack.pop()
    command.append("-")
  else:
    find = False

if not find:
  print("NO")
else:
  for i in command:
    print(i)
