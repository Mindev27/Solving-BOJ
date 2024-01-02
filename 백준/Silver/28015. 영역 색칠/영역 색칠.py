n,m = map(int,input().split())

templist = []
result = 0

def draw_count(mylist): #덧칠하는 최소횟수 구하기
  
  #0이나 빈 리스트라면 0 반환
  cnt_0 = mylist.count(0)
  if cnt_0 == len(mylist):
    return 0
  
  mylist.insert(0,0)
  cnt_1 = 0
  cnt_2 = 0
  
  #1을 덧칠할 경우
  for i in range(1, len(mylist)):
    
    if mylist[i] == 1: #1일때 앞 인덱스 확인
      if mylist[i-1] != 1:
        cnt_1 += 1
        
  cnt_1 += 1 #2를 칠하는 횟수 +1
  
  #2를 덧칠할 경우
  for i in range(1, len(mylist)):
    
    if mylist[i] == 2: #2일때 앞 인덱스 확인
      if mylist[i-1] != 2:
        cnt_2 += 1
        
  cnt_2 += 1 #1을 칠하는 횟수 +1
  
  return min(cnt_1, cnt_2)
  
  
for i in range(n):
  
  arr = list(map(int, input().split()))
  
  
  for i in arr:
    
    if(i != 0):
      templist.append(i)
      
    else:
      result += draw_count(templist)
      templist.clear()
      
  result += draw_count(templist)
  templist.clear()
  
print(result)
 