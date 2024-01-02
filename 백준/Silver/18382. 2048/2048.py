score = int(input())

temp = list(input().strip())
board = []
command = []
putnum = []
merge_score = 0

i = 0
while True:  #명령어와 숫자 넣는것 분리
  if (i >= len(temp)):
    break
  if (i % 4 == 0):
    command.append(temp[i])
  else:
    putnum.append(int(temp[i]))
  i += 1

temp = list(map(int, input().split()))

for i in range(4):  #보드 완성
  board.append(temp[i * 4:4 * (i + 1)])


def pushL():
  #왼쪽으로 밀기
  for i in range(4):
    start = 0
    blank = 0
    j = 0

    while -1 < j < 4:
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
  for i in range(4):
    start = 3
    blank = 0
    j = 3

    while 4> j > -1:
      
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
  for j in range(4):
    start = 0
    blank = 0
    i = 0

    while -1 < i < 4:

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
  for j in range(4):
    start = 3
    blank = 0
    i = 3

    while 4 > i > -1:

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
  for i in range(4):
    for j in range(3):
      if (board[i][j] == board[i][j + 1]):
        board[i][j] = board[i][j] * 2
        merge_score += board[i][j]
        board[i][j + 1] = 0


def sumR():
  global merge_score
  #오른쪽 더하기 계산
  for i in range(4):
    for j in range(3, 0, -1):
      if (board[i][j] == board[i][j - 1]):
        board[i][j] = board[i][j] * 2
        merge_score += board[i][j]
        board[i][j - 1] = 0


def sumU():
  global merge_score
  #위쪽 더하기 계산
  for j in range(4):
    for i in range(3):
      if (board[i][j] == board[i + 1][j]):
        board[i][j] = board[i][j] * 2
        merge_score += board[i][j]
        board[i + 1][j] = 0


def sumD():
  global merge_score
  #아래쪽 더하기 계산
  for j in range(4):
    for i in range(3, 0, -1):
      if (board[i][j] == board[i - 1][j]):
        board[i][j] = board[i][j] * 2
        merge_score += board[i][j]
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


cnt = 0

for i in range(len(command)):
  if (command[int(cnt / 3)] == "L"):
    mergeL()

  elif (command[int(cnt / 3)] == "R"):
    mergeR()

  elif (command[int(cnt / 3)] == "D"):
    mergeD()

  else:
    mergeU()

  a = putnum[cnt]
  x = putnum[cnt + 1]
  y = putnum[cnt + 2]

  board[x][y] = a

  cnt += 3

print(score + merge_score)
