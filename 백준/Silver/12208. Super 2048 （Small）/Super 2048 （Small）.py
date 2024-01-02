def pushL():
  #왼쪽으로 밀기
  for i in range(n):
    start = 0
    blank = 0
    j = 0

    while -1 < j < n:
      if (board[i][j] == 0):
        blank += 1

      elif (blank != 0):
        board[i][j - blank] = board[i][j]
        board[i][j] = 0
        j = start
        blank = 0

      else:
        start += 1
      j += 1


def pushR():
  #오른쪽으로 밀기
  for i in range(n):
    start = n-1
    blank = 0
    j = n-1

    while n > j > -1:

      if (board[i][j] == 0):
        blank += 1

      elif (blank != 0):
        board[i][j + blank] = board[i][j]
        board[i][j] = 0
        j = start
        blank = 0

      else:
        start += 1

      j -= 1


def pushU():
  #위로 밀기
  for j in range(n):
    start = 0
    blank = 0
    i = 0

    while -1 < i < n:

      if (board[i][j] == 0):
        blank += 1

      elif (blank != 0):
        board[i - blank][j] = board[i][j]
        board[i][j] = 0
        i = start
        blank = 0

      else:
        start += 1
      i += 1


def pushD():
  #아래로 밀기
  for j in range(n):
    start = n-1
    blank = 0
    i = n-1

    while n > i > -1:

      if (board[i][j] == 0):
        blank += 1

      elif (blank != 0):
        board[i + blank][j] = board[i][j]
        board[i][j] = 0
        i = start
        blank = 0

      else:
        start -= 1
      i -= 1


def sumL():
  global merge_score
  #왼쪽 더하기 계산
  for i in range(n):
    for j in range(n-1):
      if (board[i][j] == board[i][j + 1]):
        board[i][j] = board[i][j] * 2
        board[i][j + 1] = 0


def sumR():
  global merge_score
  #오른쪽 더하기 계산
  for i in range(n):
    for j in range(n-1, 0, -1):
      if (board[i][j] == board[i][j - 1]):
        board[i][j] = board[i][j] * 2
        board[i][j - 1] = 0


def sumU():
  global merge_score
  #위쪽 더하기 계산
  for j in range(n):
    for i in range(n-1):
      if (board[i][j] == board[i + 1][j]):
        board[i][j] = board[i][j] * 2
        board[i + 1][j] = 0


def sumD():
  global merge_score
  #아래쪽 더하기 계산
  for j in range(n):
    for i in range(n-1, 0, -1):
      if (board[i][j] == board[i - 1][j]):
        board[i][j] = board[i][j] * 2
        board[i - 1][j] = 0


def mergeL():  #왼쪽 스와이프 시행
  pushL()
  sumL()
  pushL()


def mergeR():  #오른쪽 스와이프 시행
  pushR()
  sumR()
  pushR()


def mergeU():  #위쪽 스와이프 시행
  pushU()
  sumU()
  pushU()


def mergeD():  #아래쪽 스와이프 시행
  pushD()
  sumD()
  pushD()


testcase = int(input())


for i in range(testcase):
  n, command = input().split()
  n = int(n)

  
  board = [list(map(int, input().split())) for _ in range(n)]

  if (command == "left"):
    mergeL()

  elif (command == "right"):
    mergeR()

  elif (command == "down"):
    mergeD()

  else:
    mergeU()

  print("Case #{0}:".format(i+1))
  
  for j in range(n):
    for k in range(n):
      print(board[j][k], end=" ")
    print()