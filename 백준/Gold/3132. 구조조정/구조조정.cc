#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<pii> IQ;
vector<int> adj[1001];
vector<int> new_adj[1001];
bool visited[1001];
int parent[1001];

void input() {
  cin >> N;
  IQ.push_back({0, 0});
  memset(parent, -1, sizeof(parent));
  
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    IQ.push_back({a, i});
  }
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    parent[b] = a;
  }
}

bool cmp(int a, int b) { return IQ[a].X > IQ[b].X; }

void dfs(int node) {
  visited[node] = true;
  sort(adj[node].begin(), adj[node].end(), cmp);

  for (int i = 0; i < adj[node].size(); i++) {
    int next = adj[node][i];
    if (i == 0) {
      new_adj[node].push_back(next);
    }
    else {
      new_adj[adj[node][i - 1]].push_back(next);
    }
    if (!visited[next]) dfs(next);
  }
}

void solve() {
  memset(visited, false, sizeof(visited));

  int root = 1;
  for(int i = 1; i <= N; i++) {
    if(parent[i] == -1) {
      root = i;
      break;
    }
  }
  dfs(root);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < new_adj[i].size(); j++) {
      cout << i << ' ' << new_adj[i][j] << '\n';
    }
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
