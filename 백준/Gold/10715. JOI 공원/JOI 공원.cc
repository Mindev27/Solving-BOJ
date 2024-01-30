#include <algorithm>
#include <climits>
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

ll N, M, C, total = 0;
vector<pll> adj[100005];
ll dist[100005]; // 1번에서 i까지 최소 거리
bool visited[100005];

void input() {
  cin >> N >> M >> C;
  for (int i = 0; i < M; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    total += c;
  }
}

void dijkstra(ll start) {
  ll answer = LLONG_MAX;
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    ll curDist = pq.top().X;
    ll curNode = pq.top().Y;
    pq.pop();

    if (dist[curNode] < curDist)
      continue;

    visited[curNode] = true;

    for (auto &edge : adj[curNode]) {
      ll next = edge.X;
      ll cost = edge.Y;

      if (dist[next] > curDist + cost) {
        dist[next] = curDist + cost;
        pq.push({dist[next], next});
      }
      if(visited[next]) total -= cost;
    }
    answer = min(answer, total + dist[curNode] * C);
  }
  cout << answer;
}

void solve() {
  memset(dist, 0x3f, sizeof(dist));
  memset(visited, false, sizeof(visited));
  dijkstra(1);
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
