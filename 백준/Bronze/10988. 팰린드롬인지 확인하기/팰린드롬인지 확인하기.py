word = list(input().strip())
Palin = word[::-1]

is_same = True

for i in range(len(word)):

  if word[i] != Palin[i]:
    is_same = False

if is_same: print("1")
else: print("0")
