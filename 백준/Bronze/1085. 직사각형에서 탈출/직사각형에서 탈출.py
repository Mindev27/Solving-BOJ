x,y,w,h=map(int, input().split())

def length(k):
  if(k<0):
    return 1001;
  else:
    return k;
  

print(min(length(x),length(w-x),length(y),length(h-y)))