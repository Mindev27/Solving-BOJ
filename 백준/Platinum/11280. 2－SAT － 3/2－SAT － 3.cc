#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int SIZE = 20005;
int N, M;
vector<int> adj[SIZE]; // 각 정점에서 출발하는 간선 정보
int id, d[SIZE];       // 각 정점의 방문 순서
bool finished[SIZE];   // SCC 분리가 끝난 정점
stack<int> s;
vector<vector<int>> SCC;
int SCCnum[SIZE];      // 각 정점이 속한 SCC 번호

// not x를 반환
int oppo(int x) {
  if(x <= N) return x + N;
  else return x - N;
}

// 정점양수 i, 음수면 i + N; 
void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    if(a < 0) a = oppo(-a);
    if(b < 0) b = oppo(-b);

    adj[oppo(a)].push_back(b);
    adj[oppo(b)].push_back(a);
  }
}

int dfs(int x) {
  d[x] = ++id; // 정점의 방문 순서
  s.push(x);

  int parent = d[x];
  for(int i = 0; i < adj[x].size(); i++) {
    int y = adj[x][i];
    // 방문하지 않은 이웃
    if(d[y] == 0) parent = min(parent, dfs(y));
    // 처리 중인 이웃
    else if(!finished[y]) parent = min(parent, d[y]);
  }

  // 부모가 자기 자신인 경우
  if(parent == d[x]) {
    vector<int> scc;
    while(true) {
      int t = s.top(); s.pop();
      scc.push_back(t);
      finished[t] = true;
      SCCnum[t] = SCC.size() + 1; // SCC 번호 저장
      if(t == x) break;
    }
    sort(scc.begin(), scc.end());
    SCC.push_back(scc);
  }

  return parent;
}

void solve() {
  memset(d, 0, sizeof(d));
  memset(finished, 0, sizeof(finished));
  id = 0;

  for(int i = 1; i <= 2 * N; i++) {
    if(d[i] == 0) dfs(i);
  }

  for(int i = 0 ; i <= N; i++) {
    if(SCCnum[i] == SCCnum[i + N]) {
      cout << '0';
      return;
    }
  }
  cout << '1';
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
