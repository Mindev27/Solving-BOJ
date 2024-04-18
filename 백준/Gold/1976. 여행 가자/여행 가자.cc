#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
int adj[205][205];
int p[205];
vector<int> path;

int find(int x) {
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x > y) p[x] = y;
  else p[y] = x;
}

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> adj[i][j];
    }
  }
  path.resize(M);
  for(int i = 0; i < M; i++) {
    cin >> path[i];
  }
}
bool BFS(int s, int e) {
  bool visited[205];
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(s);
  visited[s] = true;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    if(cur == e) return true;
    
    for(int i = 1; i <= N; i++) {
      if(adj[cur][i] == 1 && !visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }

  return false;
}

void solve() {
  for(int i = 1; i <= N; i++)
    p[i] = i;

  // path[0]부터 시작 
  int cur = path[0];
  for(int i = 1; i < M; i++) {
    int nxt = path[i];

    // 같은 집합이면 도달가능
    if(find(cur) == find(nxt))
      continue;

    // nxt로 가는길이 있는지 확인
    int key = find(cur);
    bool isFind = false;
    isFind = BFS(nxt, key);

    if(isFind) merge(cur, nxt);
    else{ cout << "NO"; return; }
  }

  cout << "YES";
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