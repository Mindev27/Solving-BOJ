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

int N, M, K;
vector<pair<int, pii>> bEdges;
vector<pair<int, pii>> rEdges;
int p[1005]= {};

int find(int x) {
  if (x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if(x > y) p[x] = y;
  else p[y] = x;
}

void input() {
  bEdges.clear();
  rEdges.clear();
  for(int i = 0; i < M; i++) {
    char a; int b, c;
    cin >> a >> b >> c;
    if(a == 'B') {
      rEdges.push_back({1, {b, c}});
      bEdges.push_back({0, {b, c}});
    }
    else {
      rEdges.push_back({0, {b, c}});
      bEdges.push_back({1, {b, c}});
    }
  }
}

int kruscal(vector<pair<int, pii>> &edges) {
  sort(edges.begin(), edges.end());
  int ret = 0;
  
  for(int i = 1; i <= N; i++)
    p[i] = i;

  for(int i = 0; i < edges.size(); i++) {
    if(find(edges[i].Y.X) != find(edges[i].Y.Y)) {
      merge(edges[i].Y.X, edges[i].Y.Y);
      ret += edges[i].X;
    }
  }
  return ret;
}

void solve() {
  int maxBlue = (N - 1) - kruscal(bEdges);
  int minBlue = kruscal(rEdges);

  if(minBlue <= K && K <= maxBlue)
    cout << "1\n";
  else cout << "0\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true) {
    cin >> N >> M >> K;
    if(N == 0 && M == 0 && K == 0) break;
    input();
    solve();
  }
  
  return 0;
}
