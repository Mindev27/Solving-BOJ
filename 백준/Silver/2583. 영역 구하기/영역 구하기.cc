#include <algorithm>
#include <cmath>
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

int N, M, K;
bool visited[105][105] = {};

void input() {
  cin >> M >> N >> K;
  for(int i = 0; i < K; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int j = y1; j < y2; j++) {
      for(int k = x1; k < x2; k++) {
        visited[j][k] = true;
      }
    }
  }
}

int BFS(int a, int b) {
  int cnt = 1;
  queue<pii> q;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  q.push({a, b});
  visited[a][b] = true;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= M || ny < 0 || ny >= N || visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
      cnt++;
    }
  }
  return cnt;
}

void solve() {
  vector<int> ans;
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      if(!visited[i][j]) {
        ans.push_back(BFS(i, j));
      }
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(int &i : ans)
    cout << i << ' ';
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
