#include <bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, K;
int adj[205][205];
vector<int> f; // 친구 위치

void input() {
  cin >> N >> M;
  memset(adj, INF, sizeof(adj));

  for(int i = 1; i <= N; i++) {
    adj[i][i] = 0;
  }

  for(int i = 0; i < M; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u][v] = w;
  }

  cin >> K;
  for(int i = 0; i < K; i++) {
    int x; cin >> x;
    f.push_back(x);
  }
}

void solve() {
  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }

  vector<int> ans;
  int minTime = INF;
  for(int i = 1; i <= N; i++) {
    int curMax = 0;
    for(int one : f) {
      curMax = max(curMax, adj[i][one] + adj[one][i]);
    }

    if(curMax == INF) continue;

    if(curMax < minTime) {
      ans.clear();
      minTime = curMax;
      ans.push_back(i);
    }
    else if(curMax == minTime) {
      ans.push_back(i);
    }
  }

  sort(ans.begin(), ans.end());

  for(int i : ans) {
    cout << i << ' ';
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
