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

const int SIZE = 3005;
int n;
LINE lines[SIZE];
int parent[SIZE];
int count[SIZE] = {};

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y) parent[x] = y;
  else parent[y] = x;
}

bool findParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x == y) return true;
  else return false;
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
    else if((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC))
      return 0;
    else
      return 1;
  }
}

bool isCross(int a, int b) {
  bool is_cross = false;

  long long int abc = Direction(lines[a].s, lines[a].e, lines[b].s) *
                      Direction(lines[a].s, lines[a].e, lines[b].e);

  long long int abd = Direction(lines[b].s, lines[b].e, lines[a].s) *
                      Direction(lines[b].s, lines[b].e, lines[a].e);

  if (abc <= 0 && abd <= 0)
    is_cross = true;

  return is_cross;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> lines[i].s.x >> lines[i].s.y;
    cin >> lines[i].e.x >> lines[i].e.y;
  }
}

void solve() {
  // 유니온 파인드를 위해 정보 초기화
  for(int i = 0; i < n; i++)
    parent[i] = i;

  // 선분이 교차한다면 하나의 유니온으로 묶기
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(isCross(i, j)) unionParent(i, j);
    }
  }

  // 유니온의 개수 파악
  for(int i = 0; i < n; i++)
    count[getParent(i)]++;

  int unionNum = 0;
  int maxGroup = 0;
  for(int i = 0; i < n; i++){
    if(count[i] != 0){
      unionNum++;
      maxGroup = max(maxGroup, count[i]);
    }
  }

  cout << unionNum << '\n' << maxGroup;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();
  
  return 0;
}
