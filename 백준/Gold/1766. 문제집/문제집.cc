#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 32000;
int N, M;
vector<vector<int>> graph(MAX + 1);
vector<int> inDegree(MAX + 1, 0);
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    inDegree[b]++;
  }
}

void solve() {
  // 진입 차수가 0인 정점을 우선순위 큐에 추가
  for (int i = 1; i <= N; i++) {
    if (inDegree[i] == 0) {
      pq.push(i);
    }
  }

  // 위상 정렬
  while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();
    cout << cur << " ";

    for (int adj : graph[cur]) {
      inDegree[adj]--;
      if (inDegree[adj] == 0) {
        pq.push(adj);
      }
    }
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  input();
  solve();
  
  return 0;
}
