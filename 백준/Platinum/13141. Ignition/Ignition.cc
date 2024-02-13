#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const ll INF = 1e18;
int N, M;
int dist[205][205];
vector<pair<pii, int>> edge; // (시작, 끝, 길이)

void input() {
  cin >> N >> M;
  memset(dist, 0x3f, sizeof(dist));

  for(int i = 1; i <= N; i++)
    dist[i][i] = 0;
  
  for(int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({{a, b}, c});
    
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }
}

// i번 정점에 불을붙일때 걸리는 시간의 두배계산
ll ignition(int i) {
  ll time = 0;

  // 각 간선에 대해서 최대시간을 계산
  for(auto &e : edge) {
    int S = e.X.X, E = e.X.Y, W = e.Y;
    ll cur = dist[i][S] + dist[i][E] + W; // 이건 두배값임
    time = max(time, cur);
  }

  return time;
}

void solve() {
  // 플로이드-워셜
  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  // 각 정점에서 불을 붙이는 경우중 최단시간 계산
  ll ans = INF;
  for(int i = 1; i <= N; i++) { 
    ans = min(ans, ignition(i));
  }

  // ans는 현재 두배값
  if(ans % 2 == 0) cout << ans / 2 << ".0";
  else cout << ans / 2 << ".5";
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
