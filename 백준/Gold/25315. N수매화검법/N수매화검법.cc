#include <iostream>

using namespace std;

typedef struct {
  int x;
  int y;
} POINT;

typedef struct {
  POINT s;
  POINT e;
  int weight;
  long long int crossNum;
} LINE;

long long int Direction(POINT a, POINT b, POINT c);
bool isCross(int l1, int l2, LINE *lines);
void swap(int a, int b, LINE *lines);

int main() {
  int bladeNum;

  cin >> bladeNum;
  
  LINE *lines = new LINE[bladeNum]; // line 동적할당
  
  //입력
  for (int i = 0; i < bladeNum; i++) {
    cin >> lines[i].s.x >> lines[i].s.y;
    cin >> lines[i].e.x >> lines[i].e.y;
    cin >> lines[i].weight;
  }

  //정렬
  for(int i = 0; i < bladeNum - 1; i++){
    for(int j = 0; j < bladeNum - 1; j++){
      if(lines[j].weight > lines[j + 1].weight){
        swap(j, j + 1, lines);
      }
    }
  }

  //각 선마다 겹치는 개수 계산 후 합산
  long long int result = 0;
  for(int i = 0; i < bladeNum; i++){
    for(int j = i + 1; j < bladeNum; j++){
      if(isCross(i, j, lines)){
        lines[i].crossNum++;
      }
    }

    result += (lines[i].crossNum + 1) * lines[i].weight;
  }

  cout << result;
  
  delete[] lines;
}

//선분교차 알고리즘 함수
long long int Direction(POINT a, POINT b, POINT c) {
  long long int dxAB = b.x - a.x, dyAB = b.y - a.y;
  long long int dxBC = c.x - b.x, dyBC = c.y - b.y;

  // dyAB / dxAB > dyBC / dxBC 시계방향
  if (dyAB * dxBC > dyBC * dxAB)
    return 1;
  else
    return -1;
}

bool isCross(int l1, int l2, LINE *lines) {
  bool is_cross = true;

  long long int abc = Direction(lines[l1].s, lines[l1].e, lines[l2].s) *
                      Direction(lines[l1].s, lines[l1].e, lines[l2].e);

  long long abd = Direction(lines[l2].s, lines[l2].e, lines[l1].s) *
                  Direction(lines[l2].s, lines[l2].e, lines[l1].e);
  if (abc > 0)
    is_cross = false;

  if (abd > 0)
    is_cross = false;

  return is_cross;
}

void swap(int a, int b, LINE *lines) {
  LINE temp;
  temp = lines[a];
  lines[a] = lines[b];
  lines[b] = temp;
}

