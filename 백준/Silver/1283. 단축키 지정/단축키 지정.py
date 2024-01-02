n = int(input())

s = []
for _ in range(n):
  words = list(input().split())

  flag = False
  for i in range(len(words)):
    if words[i][0].lower() not in s:
      s.append(words[i][0].lower())
      flag = True
      words[i] = '[' + words[i][0] + ']' + words[i][1:]
      print(' '.join(words))
      break

  if not flag:
    for i in range(len(words)):
      check = False
      for j in range(len(words[i])):
        if words[i][j].lower() not in s:
          s.append(words[i][j].lower())
          flag = True
          check = True
          words[i] = words[i][:j] + '[' + words[i][j] + ']' + words[i][j + 1:]
          print(' '.join(words))
          break
      if check: break

  if not flag:
    print(' '.join(words))
