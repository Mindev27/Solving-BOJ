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

const int INF = 0x3f3f3f3f;
int N, M, T;
int dist[305][305] = {};
vector<pii> query;

void input() {
  memset(dist, INF, sizeof(dist));
  cin >> N >> M >> T;
  for(int i = 1 ; i <= N; i++) dist[i][i] = 0;
  for(int i = 0 ; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    dist[a][b] = c;
  }
  for(int i = 0 ; i < T; i++) {
    int a, b; cin >> a >> b;
    query.push_back({a, b});
  }
}

void solve() {
  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(i == k || j == k || i == j) continue;
        dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
      }
    }
  }
  
  for(pii &q : query) {
    if(dist[q.X][q.Y] == INF) cout << "-1\n";
    else cout << dist[q.X][q.Y] << '\n';
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