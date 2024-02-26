#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
int p[100005] = {};
int dist[100005] = {};

int find(int x) {
  if(p[x] == -1) return x;
  int parent = find(p[x]); // 경로 압축
  dist[x] += dist[p[x]];
  return p[x] = parent;
}

void merge(int x, int y, int w) {
  int a = find(x);
  int b = find(y);

  if(a != b) {
    dist[a] = dist[y] - dist[x] + w;
    p[a] = b;
    return;
  }
}

void solve() {
  memset(p, -1, sizeof(p));
  memset(dist, 0, sizeof(dist));

  for(int i = 0; i < M; i++) {
    char x;
    cin >> x;

    if(x == '!') {
      int a, b, w;
      cin >> a >> b >> w;
      merge(a, b, w);
    }
    else {
      int a, b;
      cin >> a >> b;
      if(find(a) == find(b)) cout << dist[a] - dist[b] << '\n';
      else cout << "UNKNOWN\n";
    }
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true) {
    cin >> N >> M;
    if(N == 0 && M == 0)
      break;
    solve();
  }

  return 0;
}
