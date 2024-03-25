#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int SIZE = 40005;
int N, M, H;
vector<pii> adj[SIZE];
vector<pii> query;
int dep[SIZE];
int p[SIZE][20];
int dist[SIZE][20];

void input() {
  cin >> N;
  for(int i = 0 ; i < N - 1; i++) {
    int x, y, z; cin >> x >> y >> z;
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }

  cin >> M;
  for(int i = 0 ; i < M; i++) {
    int x, y; cin >> x >> y;
    query.push_back({x, y});
  }
}

void labeling(int parent, int cur, int depth, int cost) {
  if(!adj[cur].size())
    return;

  p[cur][0] = parent;
  dep[cur] = depth;
  dist[cur][0] = cost;

  for(auto &next : adj[cur]) {
    if(next.X != parent)
      labeling(cur, next.X, depth + 1, next.Y);
  }
}

int findDist(int a, int b) {
  int sum = 0;
  if(dep[a] != dep[b]) {
    if(dep[a] < dep[b]) swap(a, b);

    // 높이 맞추기
    int gap = dep[a] - dep[b];
    for(int i = 0; gap > 0; i++) {
      if(gap % 2 == 1) {
        sum += dist[a][i];
        a = p[a][i];
      }
      gap = gap >> 1;
    }
  }

  if(a != b) {
    for(int i = H; i >= 0; i--) {
      if(p[a][i] != 0 && p[a][i] != p[b][i]) {
        sum += dist[a][i] + dist[b][i];
        a = p[a][i];
        b = p[b][i];
      }
    }
    sum += dist[a][0] + dist[b][0];
  }

  return sum;
}

void solve() {
  labeling(0, 1, 0, 0);

  // 트리의 최대높이 구하기
  int i = N; H = 0;
  while(i > 1) {
    i = i >> 1;
    H++;
  }

  for(int i = 1; i <= H; i++) {
    for(int j = 2; j <= N; j++) {
      if(p[j][i - 1] != 0) {
        p[j][i] = p[p[j][i - 1]][i - 1];
        dist[j][i] = dist[p[j][i - 1]][i - 1] + dist[j][i - 1];
      }
    }
  }

  for(auto i : query) {
    cout << findDist(i.X, i.Y) << '\n';
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