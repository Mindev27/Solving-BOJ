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

const int SIZE = 200005;
int N, M, sn = 0;
vector<int> adj[SIZE], sw[100005];
int id, d[SIZE];
bool finished[SIZE], isOn[100005];
stack<int> s;
int SCCnum[SIZE];

int oppo(int x) {
  return x % 2 ? x + 1 : x - 1;
}

void makeEdge(int x, int y) {
  adj[oppo(x)].push_back(y);
  adj[oppo(y)].push_back(x);
}

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> isOn[i];
  }
  for(int i = 1; i <= M; i++) {
    int t; cin >> t;
    while(t--) {
      int x; cin >> x;
      sw[x].push_back(i);
    }
  }

  for(int i = 1; i <= N; i++) {
    int a = sw[i][0] * 2;
    int b = sw[i][1] * 2;

    if(isOn[i]) {
      makeEdge(a, oppo(b));
      makeEdge(oppo(a), b);
    }
    else {
      makeEdge(a, b);
      makeEdge(oppo(a), oppo(b));
    }
  }
}

int dfs(int x) {
  d[x] = ++id;
  s.push(x);

  int parent = d[x];
  for(int i = 0; i < adj[x].size(); i++) {
    int y = adj[x][i];
    if(d[y] == 0) parent = min(parent, dfs(y));
    else if(!finished[y]) parent = min(parent, d[y]);
  }

  if(parent == d[x]) {
    while(true) {
      int t = s.top(); s.pop();
      finished[t] = true;
      SCCnum[t] = sn;
      if(t == x) break;
    }
    sn++;
  }

  return parent;
}

void solve() {
  for(int i = 1; i <= 2 * M; i++) {
    if(d[i] == 0) dfs(i);
  }

  for(int i = 1; i <= M; i++) {
    if(SCCnum[i * 2] == SCCnum[i * 2 - 1]) {
      cout << "0\n";
      return;
    }
  }

  cout << "1\n";
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