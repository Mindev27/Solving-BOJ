#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int V, E, id = 0;
vector<int> adj[10005];
int dist[10005];
bool isCut[10005];

void input() {
  cin >> V >> E;
  for(int i = 0; i < E; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

int DFS(int cur, bool isRoot) {
  int ret = dist[cur] = ++id;
  int child = 0;

  for(int next : adj[cur]) {
    if(dist[next]) { // 이미 방문했다면
      ret = min(ret, dist[next]);
      continue;
    }

    child++;
    int prev = DFS(next, false);
    if(!isRoot && prev >= dist[cur]) {
      isCut[cur] = true;
    }
    ret = min(ret, prev);
  }

  if(isRoot && child >= 2)
    isCut[cur] = true;

  return ret;
}

void solve() {
  memset(dist, 0, sizeof(dist));
  memset(isCut, false, sizeof(isCut));

  for(int i = 1; i <= V; i++) {
    if(!dist[i]) DFS(i, true);
  }

  vector<int> ans;
  for(int i = 1; i <= V; i++) {
    if(isCut[i]) ans.push_back(i);
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(int &i : ans) cout << i << ' ';
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
