#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> linked[20005];
vector<int> d[20005] = {}; // i거리에 있는 노드

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    linked[a].push_back(b);
    linked[b].push_back(a);
  }
}

void solve() {
  bool visited[20005] = {};
  queue<pair<int, int>> q; // 노드, 거리
  int maxDist = 0;
  
  q.push({1, 0});
  visited[1] = true;
  d[0].push_back(1);

  while (!q.empty()) {
    int x = q.front().first;
    int dist = q.front().second;
    q.pop();

    for (int nx : linked[x]) {
      if (!visited[nx]) {
        visited[nx] = true;
        int nDist = dist + 1;
        q.push({nx, nDist});

        d[nDist].push_back(nx); // dist거리에 있는 노드 개수 증가

        if (maxDist < nDist)
          maxDist = nDist;
      }
    }
  }
  sort(d[maxDist].begin(), d[maxDist].end());
  
  cout << d[maxDist][0] << ' ';
  cout << maxDist << ' ';
  cout << d[maxDist].size();
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
