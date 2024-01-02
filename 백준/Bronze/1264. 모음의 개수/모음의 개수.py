import sys

key = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'}

while(True):
  a = 0
  word = sys.stdin.readline()

  if word == "#\n":
    break
  else:  
    for i in word:
      if i in key:
        a += 1

  print(a)