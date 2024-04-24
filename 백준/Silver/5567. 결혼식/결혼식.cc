#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N, M;
bool adj[505][505];

void input() {
  memset(adj, false, sizeof(adj));
  cin >> N >> M;
  for(int i = 0 ; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adj[a][b] = true;
    adj[b][a] = true;
  }
}

void solve() {
  int cnt = 0;
  queue<pii> q;
  bool visited[505];
  memset(visited, false, sizeof(visited));

  q.push({1, 0});
  visited[1] = true;

  while(!q.empty()) {
    int cur = q.front().X;
    int dist = q.front().Y;
    q.pop();

    cnt++;
    if(dist == 2) continue;

    for(int i = 1; i <= N; i++) {
      if(adj[cur][i] == true && !visited[i]) {
        q.push({i, dist + 1});
        visited[i] = true;
      }
    }
  }

  cout << cnt - 1;
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
