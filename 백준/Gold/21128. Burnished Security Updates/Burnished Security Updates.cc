#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
vector<int> adj[300005];
int visited[300005];

int BFS(int x) {
  int color0 = 1, color1 = 0;
  visited[x] = 0;
  queue<int> q;
  q.push(x);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      if (visited[nxt] == visited[cur])
        return -1;

      if (visited[nxt] == -1) {
        visited[nxt] = visited[cur] == 1 ? 0 : 1;
        if (visited[nxt] == 0) color0++;
        else color1++;
        q.push(nxt);
      }
    }
  }

  return min(color0, color1);
}

void solve() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  memset(visited, -1, sizeof(visited));

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (visited[i] == -1) {
      int a = BFS(i);
      if (a == -1) {
        cout << "-1\n";
        return;
      }
      ans += a;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
