#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N, M;
int dist[500005];
vector<int> adj[500005];

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> dist[i];
  }
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    if(abs(dist[a] - dist[b]) == 1) {
      int startV = dist[a] > dist[b] ? a : b;
      int endV = dist[a] > dist[b] ? b : a;
      adj[startV].push_back(endV);
    }
    else {
      if(dist[a] == 0) {adj[a].push_back(b);}
      else {adj[b].push_back(a);}
    }
  }
}

int BFS(int start) {
  bool visited[500005];
  memset(visited, false, sizeof(visited));
  queue<int> q;

  q.push(start);
  visited[start] = true;
  int ans = 0;
  
  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    bool isNext = false;
    for(int i = 0; i < adj[cur].size(); i++) {
      int nxt = adj[cur][i];

      isNext = true;
      
      if(visited[nxt] == false) {
        visited[nxt] = true;
        q.push(nxt);
      }
    }

    if(!isNext) {
      ans = cur; break;
    }
  }

  return ans;
}

void solve() {
  cout << BFS(1);
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
