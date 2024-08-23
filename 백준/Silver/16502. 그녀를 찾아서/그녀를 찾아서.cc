#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int T, M;
queue<pair<pair<int, ld>, int>> q;
vector<pair<int, ld>> adj[4];
ld ans[4];

void solve() {
  cin >> T >> M;
  for(int i = 0; i < M; i++) {
    char x, y; ld p;
    cin >> x >> y >> p;
    adj[x-'A'].push_back({y-'A', p});
  }

  for(int i = 0 ; i < 4; i++) {
    q.push({{i, 25.0f}, 0});
    ans[i] = 0;
  }
    
  while(!q.empty()) {
    int cur = q.front().X.X;
    ld p = q.front().X.Y;
    int step = q.front().Y;
    q.pop();

    if(step == T) {
      ans[cur] += p;
      continue;
    }
    
    for(int i = 0 ; i < adj[cur].size(); i++) {
      int next = adj[cur][i].X;
      ld np = p * adj[cur][i].Y;

      q.push({{next, np}, step + 1});
    }
  }

  for(int i = 0 ; i < 4; i++) {
    cout << ans[i] << '\n';
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
