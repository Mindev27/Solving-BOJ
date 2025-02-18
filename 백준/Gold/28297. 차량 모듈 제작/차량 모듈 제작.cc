#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct {
  int x;
  int y;
  int r;
} Circle;

const int SIZE = 1005;
int n;
int parent[SIZE] = {};
Circle gears[SIZE] = {};
vector<pair<double, pair<int, int>>> dist; // 거리, 시작원, 끝원

// 부모를 찾는 함수
int getParent(int x) {
  if (parent[x] == x)
    return x;
  return parent[x] = getParent(parent[x]);
}

// 두 값을 하나의 유니온으로 묶는 함수
void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y)
    parent[x] = y;
  else
    parent[y] = x;
}

// 둘의 부모 노드가 같은지 확인
bool findParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x == y)
    return true;
  else
    return false;
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> gears[i].x >> gears[i].y >> gears[i].r;
    parent[i] = i;
  }
}

int power(int a) { return a * a; }

double chainLength(Circle &a, Circle &b) {
  int x1, x2, y1, y2, r1, r2;
  
  if(a.r > b.r){
    x1 = a.x, y1 = a.y, r1 = a.r;
    x2 = b.x, y2 = b.y, r2 = b.r;
  }
  else{
    x1 = b.x, y1 = b.y, r1 = b.r;
    x2 = a.x, y2 = a.y, r2 = a.r;
  }
  

  double result = 0;
  
  // 중심 사이의 거리
  double distance = sqrt(power(x1 - x2) + power(y1 - y2));

  // 원 사이에 직선 거리
  result += 2 * sqrt((distance * distance) - power(r1 - r2));

  // 호의 길이
  result += r1 * (2 * M_PI - 2 * acos((double)(r1 - r2) / distance));
  result += r2 * 2 * acos((double)(r1 - r2) / distance);
  

  return result;
}

// 두 원이 겹치는지 판별
bool isCrssed(Circle &a, Circle &b) {
  int x1 = a.x, y1 = a.y, r1 = a.r;
  int x2 = b.x, y2 = b.y, r2 = b.r;

  return power(x1 - x2) + power(y1 - y2) <= power(r1 + r2);
}

long double kruskal(){
  long double result = 0;

  sort(dist.begin(), dist.end());
  
  for(int i = 0; i < dist.size(); i++){
    double weight = dist[i].first;
    int startNode = dist[i].second.first;
    int endNode = dist[i].second.second;
    
    //유니온 파인드로 간선을 선택할수 있는지 확인
    if(findParent(startNode, endNode)) continue;

    result += weight;
    unionParent(startNode, endNode);
  }

  return result;
}

double solve() {
  // 두 원이 겹치는지 판별
  for(int i = 1; i <= n - 1; i++){
    for(int j = i + 1; j <= n; j++){
      
      if(isCrssed(gears[i], gears[j])){ // 겹친다면
        unionParent(i, j); // 하나의 유니온으로 묶기
      }
        
      else{ // 겹치지 않으면
        double weight = chainLength(gears[i], gears[j]);
        dist.push_back({weight, {i, j}}); // 거리 벡터에 저장
      }
    }
  }

  
  return kruskal();
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  cout << fixed;
  cout.precision(15);
  cout << solve();
}