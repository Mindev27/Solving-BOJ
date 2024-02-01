def find(ans):
  if(a == layer): # 오른쪽 면
    return ans + b

  ans -= layer  
  if(b == -layer): # 오른쪽 윗면
    return ans - layer + a

  ans -= layer
  if(a + b == -layer): # 왼쪽 윗면
    return ans + a

  ans -= layer
  if(a == -layer): # 왼쪽 면
    return ans - b

  ans -= layer
  if(b == layer): # 왼쪽 아랫면
    return ans - (layer + a)

  ans -= layer
  if(a + b == layer): # 오른쪽 아랫면
    return ans - a

a, b = map(int, input().split())
layer = max(abs(a), abs(b), abs(a+b))

# layer번째일때 최댓값
maxVal = 3 * layer * (layer + 1) + 1
print(find(maxVal))
