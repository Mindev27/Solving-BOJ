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

const int SIZE = 4040;
int N, M, sn = 0;
vector<int> adj[SIZE];
int id, d[SIZE];
bool finished[SIZE];
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
    string temp; cin >> temp;
    for(int j = 1; j <= M; j++) {
      int a = i * 2;
      int b = ((j + N) * 2);
      if(temp[j - 1] == '#') { // 위치 추적기인 경우
        makeEdge(a, oppo(b));
        makeEdge(oppo(a), b);
      }
      else if(temp[j - 1] == '*') { // 보석인 경우
        makeEdge(a, b);
        makeEdge(oppo(a), oppo(b));
      }
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
  for(int i = 1; i <= 2 * (N + M); i++) {
    if(d[i] == 0) dfs(i);
  }

  for(int i = 1; i <= N + M; i++) {
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