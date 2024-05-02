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

int V, E, cnt;
vector<int> adj[100001];
int num[100001];
int par[100001];
int low[100001];
vector<pii> ans;

void input() {
  cin >> V >> E;
  for(int i = 0; i < E; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void dfs(int x) {
  num[x] = cnt++;
  low[x] = cnt;
  for (int nxt : adj[x]) {
    if (nxt == par[x]) continue;
    
    if (num[nxt] == 0) {
      par[nxt] = x;
      dfs(nxt);
      if (low[nxt] > num[x])
        ans.push_back({min(x, nxt), max(x, nxt)});
      low[x] = min(low[x], low[nxt]);
    }
    else low[x] = min(low[x], num[nxt]);
  }
}

void solve() {
  dfs(1);

  for(pii &p : ans) {
    int from = min(p.X, p.Y);
    int to = max(p.X, p.Y);
    p = {from, to};
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for(pii &p : ans) cout << p.X << ' ' << p.Y << '\n';
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
