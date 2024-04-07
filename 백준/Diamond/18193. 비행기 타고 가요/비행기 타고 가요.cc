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

struct Ticket {
  int cost;
  int a, b, c, d;
};
const ll INF = 1e18;
int N, M, K;
vector<vector<pll>> adj;
vector<Ticket> tickets;

void input() {
  cin >> N >> M >> K;
  for(int i = 0 ; i < M; i++) {
    int cost, a, b, c, d;
    cin >> cost >> a >> b >> c >> d;
    tickets.push_back({cost, a, b, c, d});
  }
}

void djkstra(int sz, int h) {
  vector<ll> dist(sz, INF);
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  dist[K + h * 2] = 0;
  pq.push({dist[K + h * 2], K + h * 2});

  while(!pq.empty()) {
    ll cost = pq.top().X;
    ll cur = pq.top().Y;
    pq.pop();

    if(dist[cur] != cost) continue;
    for(pll i : adj[cur]) {
      if(dist[i.Y] > cost + i.X) {
        dist[i.Y] = cost + i.X;
        pq.push({dist[i.Y], i.Y});
      }
    }
  }
  
  for(int i = h * 3; i < h * 3 + N; i++) {
    if(dist[i] == INF) cout << -1 << ' ';
    else cout << dist[i] << ' ';
  }
}

void solve() {
  ll h = 1;
  while(h < N)
      h <<= 1;
  adj.resize(h << 2);
  K = (K - 1) | h;

  // 간선 만들기
  for(int i = 1; i < h; i++) {
    adj[i].push_back({0, i * 2});
    adj[i].push_back({0, i * 2 + 1});
  }
  for(int i = h; i < h * 2; i++) {
    adj[i].push_back({0, i + h * 2});
  }
  for(int i = 1; i < h; i++) {
    adj[i * 2 + h * 2].push_back({0, i + h * 2});
    adj[i * 2 + 1 + h * 2].push_back({0, i + h * 2});
  }

  for(Ticket &i : tickets) {
    adj.push_back(vector<pll>{});
    i.a = (i.a - 1) | h; i.b = (i.b - 1) | h;
    i.c = (i.c - 1) | h; i.d = (i.d - 1) | h;
    while(i.a <= i.b) {
      if(i.a % 2) {
        adj[i.a + h * 2].push_back({0, adj.size() - 1});
        i.a++;
      }
      if(~i.b % 2) {
        adj[i.b + h * 2].push_back({0, adj.size() - 1});
        i.b--;
      }
      i.a >>= 1, i.b >>= 1;
    }
    while(i.c <= i.d) {
      if(i.c % 2) {
        adj.back().push_back({i.cost, i.c});
        i.c++;
      }
      if(~i.d % 2) {
        adj.back().push_back({i.cost, i.d});
        i.d--;
      }
      i.c >>= 1, i.d >>= 1;
    }
  }
  
  djkstra(adj.size(), h);
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