#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
int degree[500005];
vector<int> adj[500005];
int visited[500005];

void dfs(int x, int color) {
  visited[x] = color;
  for(int i : adj[x]) {
    if(visited[i] == -1 && degree[i] == 2) {
      dfs(i, color);
    }
  }
}

void solve() {
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    degree[a]++;
    degree[b]++;
  }

  memset(visited, -1, sizeof(visited));
  
  for(int i = 1; i <= N; i++) {
    if(visited[i] == -1 && degree[i] == 1) {
      visited[i] = 0;
      for(int nxt : adj[i]) {
        if(visited[nxt] == -1 && degree[nxt] == 2) dfs(nxt, 0);
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(visited[i] == 0) {
      for(int j : adj[i]) degree[j]--;
    }
  }
  
  for(int i = 1; i <= N; i++) {
    if(visited[i] == -1 && degree[i] == 1) {
      visited[i] = 1;
      for(int nxt : adj[i]) {
        if(visited[nxt] == -1 && degree[nxt] == 2) dfs(nxt, 1);
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(visited[i] == 1) {
      for(int j : adj[i]) degree[j]--;
    }
  }

  for(int i = 1; i <= N; i++) {
    if(visited[i] == -1 && degree[i] > 2) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}

