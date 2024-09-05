#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
vector<int> adj[1000005];
int color[1000005];

bool BFS(int x, int c) {
  color[x] = c;
  queue<pii> q;
  q.push({x, c});

  while (!q.empty()) {
    int cur = q.front().X;
    int col = q.front().Y;
    q.pop();

    for (int i = 0; i < adj[cur].size(); i++) {
      int next = adj[cur][i];
      if(color[cur] == color[next]) return false;
      if(color[next] != -1) continue;

      color[next] = col == 0 ? 1 : 0;
      q.push({next, color[next]});
    }
  }

  return true;
}

void solve() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  // 이분그래프 확인
  memset(color, -1, sizeof(color));
  for(int i = 1; i <= N; i++) {
    bool flag;
    if(color[i] == -1) {
      flag = BFS(i, 1);
      if(flag == false) {
        cout << "IMPOSSIBLE";
        return;
      }
    }    
  }

  cout << "POSSIBLE";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
