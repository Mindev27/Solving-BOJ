#include <iostream>
#include <vector>

using namespace std;

int n, farFrom1;
long long maxDist;
vector<pair<int, int>> linked[100001]; // 다음노드, 가중치
bool visited[100001] = {};

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int idx;
    cin >> idx;
    int a, b;
    while (true) {
      cin >> a;
      if (a == -1)
        break;
      cin >> b;
      linked[idx].push_back({a, b});
    }
  }
}

void init() {
  maxDist = -1;
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
}

void dfs(int k, long long w) {
  visited[k] = true;

  for (int i = 0; i < linked[k].size(); i++) {
    int next = linked[k][i].first;
    int dist = linked[k][i].second;

    if (!visited[next]) // 방문하지 않은 노드를 재귀적으로 호출
      dfs(next, w + dist);
  }

  if (maxDist < w) { // 탐색 후 최대거리 업데이트
    maxDist = w;
    farFrom1 = k;
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  init();
  dfs(1, 0); // 1과 가장 먼 노드 구하기

  init();
  dfs(farFrom1, 0); // 먼 노드 기준 가장 멀리있는 거리가 최대
  cout << maxDist;
}
