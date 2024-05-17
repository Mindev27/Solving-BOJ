#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <set>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int V, E;
vector<int> adj[100001]; // 각 정점에서 출발하는 간선 정보
int id, d[100001];       // 각 정점의 방문 순서
bool finished[100001];   // SCC 분리가 끝난 정점
stack<int> s;
vector<vector<int>> SCC;
int SCCnum[100001];      // 각 정점이 속한 SCC 번호

void input() {
  cin >> V >> E;
  for (int i = 0; i < V; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
}

int dfs(int x) {
  d[x] = ++id; // 정점의 방문 순서
  s.push(x);

  int parent = d[x];
  for (int y : adj[x]) {
    // 방문하지 않은 이웃
    if (d[y] == 0) parent = min(parent, dfs(y));
    // 처리 중인 이웃
    else if (!finished[y]) parent = min(parent, d[y]);
  }

  // 부모가 자기 자신인 경우
  if (parent == d[x]) {
    vector<int> scc;
    while (true) {
      int t = s.top();
      s.pop();
      scc.push_back(t);
      finished[t] = true;
      SCCnum[t] = SCC.size(); // SCC 번호 저장
      if (t == x) break;
    }
    sort(scc.begin(), scc.end());
    SCC.push_back(scc);
  }

  return parent;
}

void solve() {
  memset(d, 0, sizeof(d));
  memset(finished, 0, sizeof(finished));
  memset(SCCnum, 0, sizeof(SCCnum));
  id = 0;
  SCC.clear();

  for (int i = 0; i < V; i++) {
    if (d[i] == 0) dfs(i);
  }

  // 새 그래프 구성
  vector<set<int>> newAdj(SCC.size());
  vector<int> indegree(SCC.size(), 0);

  for (int i = 0; i < V; i++) {
    for (int j : adj[i]) {
      if (SCCnum[i] != SCCnum[j]) {
        if (newAdj[SCCnum[i]].insert(SCCnum[j]).second) {
          indegree[SCCnum[j]]++;
        }
      }
    }
  }

  // indegree가 0인 SCC 개수 세기
  int result = 0;
  int idx = 0;
  for (int i = 0; i < indegree.size(); i++) {
    if (indegree[i] == 0) { result++; idx = i; }
  }

  if(result == 1) {
    sort(SCC[idx].begin(), SCC[idx].end());
    for(auto i : SCC[idx]) {
      cout << i << '\n';
    }
  }
  else cout << "Confused\n";

  cout << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc;
  cin >> Tc;
  while (Tc--) {
    input();
    solve();
  }

  return 0;
}
