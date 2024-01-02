def P3(x, y, z):
  if max(x, y, z) == 100:
    return ((x - 100)**2 + (y - 100)**2 + (z - 100)**2)**0.5
  else:
    key1 = sorted([x, y, z])[1]
    key2 = sorted([x, y, z])[2]
    return min((200 - key1)**2 + (100 - key2)**2,
               (200 - key2)**2 + (100 - key1)**2)**0.5

