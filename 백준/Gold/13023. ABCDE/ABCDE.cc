#include <algorithm>
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

int N, M;
vector<int> adj[2005];
bool visited[2005];
bool isOK = false;

void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void DFS(int cur, int depth) {
  if(depth == 5) {
    isOK = true;
    return;
  }

  visited[cur] = true;

  for(int i = 0; i < adj[cur].size(); i++) {
    int next = adj[cur][i];
    if(!visited[next]){
      DFS(next, depth + 1);
      visited[next] = false;
    }
  }
}

void solve() {
  for(int i = 0; i < N; i++) {
    if(!isOK)
      DFS(i, 1);
    visited[i] = false;
  }

  if(isOK) cout << 1;
  else cout << 0;
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
