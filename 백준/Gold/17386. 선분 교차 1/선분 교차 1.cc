#include <iostream>

using namespace std;

typedef struct {
  int x;
  int y;
} POINT;

typedef struct {
  POINT s;
  POINT e;
} LINE;

long long int Direction(POINT a, POINT b, POINT c);
bool isCross(LINE *lines);

int main() {
  LINE lines[2] = {};
  
  //입력
  for (int i = 0; i < 2; i++) {
    cin >> lines[i].s.x >> lines[i].s.y;
    cin >> lines[i].e.x >> lines[i].e.y;
  }

  if(isCross(lines))
    cout << 1;
  else
    cout << 0;
}

//선분교차 알고리즘 함수
long long int Direction(POINT a, POINT b, POINT c) {
  long long int dxAB = b.x - a.x, dyAB = b.y - a.y;
  long long int dxAC = c.x - a.x, dyAC = c.y - a.y;

  // dyAB / dxAC < dyAC / dxBC 시계방향
  if (dyAB * dxAC > dyAC * dxAB)
    return 1;
  else if (dyAB * dxAC < dyAC * dxAB)
    return -1;
  else{
    if(dxAB == 0 && dyAB == 0)
      return 0;
    if((dxAB * dxAC < 0) || (dyAB * dyAC < 0))
      return -1;
    else if((dxAB * dxAB + dyAB * dyAB) >=
                    (dxAC * dxAC + dyAC * dyAC))
      return 0;
    else
      return 1;
  }
}

bool isCross(LINE *lines) {
  bool is_cross = false;

  long long int abc = Direction(lines[0].s, lines[0].e, lines[1].s) *
                      Direction(lines[0].s, lines[0].e, lines[1].e);

  long long int abd = Direction(lines[1].s, lines[1].e, lines[0].s) *
                  Direction(lines[1].s, lines[1].e, lines[0].e);
  
  if (abc <= 0 && abd <= 0)
    is_cross = true;
  
  return is_cross;
}

