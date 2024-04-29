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
vector<pii> adj[105]; // 0이면 가벼운쪽으로, 1이면 무거운쪽으로
bool visited[105];

void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back({b, 1}); // a가 b보다 무거움 
    adj[b].push_back({a, 0}); // b가 a보다 가벼움
  }
}

// type과 연결되어있는 정점의 수를 세기
int dfs(int cur, int type) {
  visited[cur] = true;
  int ret = 1;
  for(pii nxt : adj[cur]) {
    if(visited[nxt.X] || nxt.Y != type) continue;
    ret += dfs(nxt.X, type);
  }
  return ret;
}

void solve() {
  int result = 0;
  
  // N보다 작은 구슬의 개수 세기
  for(int i = 1; i <= N; i++) {
    memset(visited, false, sizeof(visited));
    int minNum = dfs(i, 0);
    if(minNum - 1 > N / 2) result++;
  }

  // N보다 큰 구슬의 개수 세기
  for(int i = 1; i <= N; i++) {
    memset(visited, false, sizeof(visited));
    int maxNum = dfs(i, 1);
    if(maxNum - 1 > N / 2) result++;
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
