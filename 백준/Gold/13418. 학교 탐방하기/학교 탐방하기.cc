#include <algorithm>
#include <queue>
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

vector<pair<int, pii>> adj;
int N, M, start = 0;
int p[1005];

int find(int x){
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void uni(int a, int b) {
  a = find(a);
  b = find(b);
  if(a != b) {
    if(a > b) p[a] = b;
    else p[b] = a;
  }
}

void input() {
  cin >> N >> M;
  int a, b, c;
  cin >> a >> b >> c;
  if(c == 0) start = 1;
  else start = 0;
  
  for(int i = 0 ; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj.push_back({c, {a, b}});
  }
}

void solve() {
  sort(adj.begin(), adj.end());
  
  for(int i = 0; i <= N; i++)
    p[i] = i;

  int worstCost = start;
  for(auto &cur : adj) {
    if(find(cur.Y.X) != find(cur.Y.Y)) {
      if(cur.X == 0) {
        worstCost++;
      }
      uni(cur.Y.X, cur.Y.Y);
    }
  }

  reverse(adj.begin(), adj.end());
  
  for(int i = 0; i <= N; i++)
    p[i] = i;

  int bestCost = start;
  for(auto &cur : adj) {
    if(find(cur.Y.X) != find(cur.Y.Y)) {
      if(cur.X == 0) {
        bestCost++;
      }
      uni(cur.Y.X, cur.Y.Y);
    }
  }

  cout << worstCost * worstCost - bestCost * bestCost;
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
