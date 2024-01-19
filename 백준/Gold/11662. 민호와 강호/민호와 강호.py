import math

def distance(x1, y1, x2, y2):

    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def closestDist(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy):

  start, end = 0, 1

  while end - start > 1e-9:

      mid1 = start + (end - start) / 3

      mid2 = end - (end - start) / 3

      x1, y1 = Ax + (Bx - Ax) * mid1, Ay + (By - Ay) * mid1

      x2, y2 = Cx + (Dx - Cx) * mid1, Cy + (Dy - Cy) * mid1

      x3, y3 = Ax + (Bx - Ax) * mid2, Ay + (By - Ay) * mid2

      x4, y4 = Cx + (Dx - Cx) * mid2, Cy + (Dy - Cy) * mid2

      dist1 = distance(x1, y1, x2, y2)

      dist2 = distance(x3, y3, x4, y4)

      if dist1 < dist2:

          end = mid2

      else:

          start = mid1

  x1, y1 = Ax + (Bx - Ax) * start, Ay + (By - Ay) * start

  x2, y2 = Cx + (Dx - Cx) * start, Cy + (Dy - Cy) * start

  return "{:.10f}".format(distance(x1, y1, x2, y2))

Ax, Ay, Bx, By, Cx, Cy, Dx, Dy = map(int, input().split())

print(closestDist(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy))

