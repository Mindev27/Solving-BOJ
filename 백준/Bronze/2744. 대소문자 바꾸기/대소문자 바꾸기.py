word = input()
result = []

for i in word:
  if i.isupper():
    result.append(i.lower())
  else:
    result.append(i.upper())

print(''.join(result))