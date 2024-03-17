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

const int SIZE = 20005;
int N, M, sn = 0;
vector<int> adj[SIZE];
int id, d[SIZE];
bool finished[SIZE];
stack<int> s;
int SCCnum[SIZE];
vector<pii> p;

int oppo(int x) {
  return x % 2 ? x + 1 : x - 1;
}

void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a = (a <= 0 ? (-a) * 2 : a * 2 - 1);
    b = (b <= 0 ? (-b) * 2 : b * 2 - 1);

    adj[oppo(a)].push_back(b);
    adj[oppo(b)].push_back(a);
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
  memset(d, 0, sizeof(d));
  memset(finished, 0, sizeof(finished));
  id = 0;

  for(int i = 1; i <= 2 * N; i++) {
    if(d[i] == 0) dfs(i);
  }

  for(int i = 1; i <= N; i++) {
    if(SCCnum[i * 2] == SCCnum[i * 2 - 1]) {
      cout << "0\n";
      return;
    }
  }

  cout << "1\n";
  int result[SIZE];
  memset(result, -1, sizeof(result));

  for(int i = 1; i <= N * 2; i++)
    p.push_back({SCCnum[i], i});

  sort(p.begin(), p.end(), greater<pii>());

  for(pii &cur : p) {
    int var = (cur.Y + 1) / 2;
    if(result[var] == -1) {
        result[var] = cur.Y % 2 ? 0 : 1;
    }
  }

  for(int i = 1; i <= N; i++)
    cout << result[i] << ' ';
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
