word = []

for i in range(5):
  word.append(list(input().strip()))

result = []

for i in range(15):
  for j in range(5):
    try:
      result.append(word[j][i])
    except:
      pass

for i in result:
  print(i, end = "")
      
  