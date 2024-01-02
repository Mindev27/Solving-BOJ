T = int(input())

for i in range(T):
  
  n, index = map(int, input().split())
  printer = list(map(int, input().split()))
  cnt = 0

  while printer:
    
    if(printer[0] == max(printer) and index == 0):
      break

    elif(printer[0] == max(printer)):
      del printer[0]
      index -= 1
      cnt += 1
        
    elif(printer[0] < max(printer) and index == 0):
      printer.append(printer[0]) 
      del printer[0]
      index = len(printer) - 1
      

    else:
      printer.append(printer[0])
      del printer[0]
      index -= 1

    

  print(cnt+1)

      

      
        