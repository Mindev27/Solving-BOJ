#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

const int SIZE = 1005;
const int MAX = 100000000;
int cnt = 0;
int n, m, s, e;
int dist[1001];
int pre[1001]; // 이전경로 저장
vector<pair<int, int>> v[1001];

void input() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    dist[i] = MAX;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
  }

  cin >> s >> e;
}

void dijkstra() {
  priority_queue<pair<int, int>> pq;
  pq.push({0, s});
  dist[s] = 0;
  
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (cost > dist[cur]) // 필요없는 연산 제거
      continue;

    for (int i = 0; i < v[cur].size(); i++) {
      int ncost = v[cur][i].second;
      int ncur = v[cur][i].first;

      if (dist[ncur] > cost + ncost) {
        dist[ncur] = ncost + cost;
        pq.push({-dist[ncur], ncur});
        pre[ncur] = cur;
      }
    }
  }
}

void printPath() {
  stack<int> path;
  path.push(e);
  int a = pre[e];
  while (a) {
    path.push(a);
    a = pre[a];
  }

  cout << dist[e] << '\n';
  cout << path.size() << '\n';
  while(!path.empty()){
    cout << path.top() << ' ';
    path.pop();
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  input();
  dijkstra();
  printPath();

  return 0;
}