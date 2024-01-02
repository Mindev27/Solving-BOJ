#include <iostream>

using namespace std;

typedef struct {
  int x;
  int y;
} POINT;

long long int CCW(POINT a, POINT b, POINT c);

int main() {
  POINT *points = new POINT[3]; // line 동적할당

  //입력
  for(int i = 0; i < 3; i++){
    int a, b;
    cin >> a >> b;
    points[i].x = a;
    points[i].y = b;
  }

  cout << CCW(points[0], points[1], points[2]);
  
  delete[] points;
}

//선분교차 알고리즘 함수
long long int CCW(POINT a, POINT b, POINT c) {
  long long int dxAB = b.x - a.x, dyAB = b.y - a.y;
  long long int dxBC = c.x - b.x, dyBC = c.y - b.y;

  // dyAB / dxAB > dyBC / dxBC 시계방향
  if (dyAB * dxBC > dyBC * dxAB)
    return -1;
  else if (dyAB * dxBC < dyBC * dxAB)
    return 1;
  else
    return 0;
}