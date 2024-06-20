#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, K, S, D;
int dist[1005][1005];
vector<pii> adj[1005];
vector<int> query;

void input() {
  memset(dist, INF, sizeof(dist));
  cin >> N >> M >> K;
  cin >> S >> D;
  S--, D--;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  query.push_back(0);
  for (int i = 0; i < K; i++) {
    int a;
    cin >> a;
    query.push_back(a);
  }
}

void solve() {
  // 먼저 다익스트라로 지나는정점마다의 거리를 게산
  priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>
      pq;
  pq.push({0, {S, 0}});
  dist[S][0] = 0;

  while (!pq.empty()) {
    int d = pq.top().X;
    int cur = pq.top().Y.X;
    int cnt = pq.top().Y.Y;
    pq.pop();

    if (cnt == N) // N개를 모두 탐색했다면 종료
      continue;

    if (dist[cur][cnt] >= d) {
      for (const auto &edge : adj[cur]) {
        int next = edge.X;
        int nDist = d + edge.Y;

        if (dist[next][cnt + 1] > nDist) {
          dist[next][cnt + 1] = nDist;
          pq.push({nDist, {next, cnt + 1}});
        }
      }
    }
  }

  
  for (int tax : query) {
    int ans = INF;
    for (int i = 0; i <= N; i++) {
      dist[D][i] += i * tax;
      ans = min(ans, dist[D][i]);
    }
    cout << ans << '\n';
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
