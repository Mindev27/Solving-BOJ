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

int N;
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
vector<int> adj[1100];
int p[1100];

int find(int x) {
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void Union(int x, int y) {
  x = find(x);
  y = find(y);
  if(x > y) p[x] = y;
  else p[y] = x;
}

void input() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j++) {
      if(i == j) continue;
      int a; cin >> a;
      pq.push({a, {i, j}});
    }
  }
}

void solve() {
  for(int i = 1; i <= N; i++) p[i] = i;
  
  while(!pq.empty()) {
    int from = pq.top().Y.X;
    int to = pq.top().Y.Y;
    pq.pop();
    
    if(find(from) == find(to))
      continue;

    Union(from, to);
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  for(int i = 1; i <= N; i++) {
    sort(adj[i].begin(), adj[i].end());
    cout << adj[i].size() << ' ';
    for(int j : adj[i])
      cout << j << ' ';
    cout << '\n';
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