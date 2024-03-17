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

const int SIZE = 2005;
int N, M, sn = 0;
vector<int> adj[SIZE];
int id, d[SIZE];
bool finished[SIZE];
stack<int> s;
int SCCnum[SIZE];
vector<pii> p;

void init() {
  id = sn = 0;
  memset(d, 0, sizeof(d));
  memset(finished, 0, sizeof(finished));
  memset(SCCnum, 0, sizeof(SCCnum));
  while(!s.empty()) s.pop();
  for (int i = 0; i < SIZE; i++)
    adj[i].clear();
  p.clear();
}

int oppo(int x) {
  return x % 2 ? x + 1 : x - 1;
}

void input() {
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a = (a <= 0 ? (-a) * 2 : a * 2 - 1);
    b = (b <= 0 ? (-b) * 2 : b * 2 - 1);

    adj[oppo(a)].push_back(b);
    adj[oppo(b)].push_back(a);
  }

  adj[2].push_back(1); // (x1 v x1) 절을 추가
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
  for(int i = 1; i <= 2 * N; i++) {
    if(d[i] == 0) dfs(i);
  }

  for(int i = 1; i <= N; i++) {
    if(SCCnum[i * 2] == SCCnum[i * 2 - 1]) {
      cout << "no\n";
      return;
    }
  }

  cout << "yes\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(cin >> N >> M) {
    init();
    input();
    solve();
  }

  return 0;
}