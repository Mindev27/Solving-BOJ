#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct POINT{
  float x;
  float y;
};

int N;
int parent[105] = {};
POINT star[105] = {};
vector<pair<float, pair<int, int>>> edges;

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

void input() {
  cin >> N;
  for(int i = 1; i <= N; ++i){
    cin >> star[i].x >> star[i].y;
    parent[i] = i;
  }
}

float kruscal() {
  float result = 0;
  for(int i = 0; i < edges.size(); ++i){
    float cost = edges[i].first;
    int x = edges[i].second.first;
    int y = edges[i].second.second;

    if(!findParent(x, y)){
      unionParent(x, y);
      result += cost;
    }
  }

  return result;
}

void solve() {
  // 거리 만들기
  for(int i = 1; i <= N; ++i){
    for(int j = i + 1; j <= N; ++j){
      float dist = sqrt((star[i].x - star[j].x) * (star[i].x - star[j].x)
                  + (star[i].y - star[j].y) * (star[i].y - star[j].y));
      edges.push_back({dist, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());

  cout << fixed;
  cout.precision(4);
  cout << kruscal();
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();
  
  return 0;
}
