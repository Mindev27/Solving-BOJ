import math

a = int(input())

for i in range(a):
  word = input()

  #접두사 정의
  length = math.ceil(len(word)/3)
  substr = word[0:length]

  #경우를 따져보기
  isPrint = False;
  result = substr + substr[::-1] + substr
  if result == word and not isPrint:
    print("1")
    isPrint = True
   
  result = substr + substr[::-1][1:] + substr
  if result == word and not isPrint:
    print("1")
    isPrint = True
    
  result = substr + substr[::-1] + substr[1:]
  if result == word and not isPrint:
    print("1")
    isPrint = True
  
  result = substr + substr[::-1][1:] + substr[1:]
  if result == word and not isPrint:
    print("1")
    isPrint = True

  if not isPrint:
    print("0")