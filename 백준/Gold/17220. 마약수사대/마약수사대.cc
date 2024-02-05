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

ll N, M;
vector<int> adj[30];
bool visited[30] = {};
int in[30] = {};

void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    char a, b;
    cin >> a >> b;
    adj[a - 'A'].push_back(b - 'A');
    in[b - 'A']++;
  }
  int c; cin >> c;
  for(int i = 0; i < c; i++) {
    char x; cin >> x;
    visited[x - 'A'] = true;
  }
}

void solve() {
  int result = 0;
  queue<int> q;
  for(int i = 0; i < N; i++) {
    if(in[i] == 0 && !visited[i]) // 마약 공급하는 곳
      q.push(i);
  }

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    for(int i = 0; i < adj[cur].size(); i++) {
      int next = adj[cur][i];
      if(visited[next]) continue; // 검거됨

      q.push(next);
      result++;
    }
  }

  cout << result;
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
