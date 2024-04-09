#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M, P, block;
int S[10], cnt[10];
int board[1005][1005];
queue<pair<pii, int>> q[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[1005][1005];

void input() {
  cin >> N >> M >> P;
  for(int i = 1; i <= P; i++) {
    cin >> S[i];
  }
  for(int i = 0; i < N; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < M; j++) {
      if(temp[j] == '.') board[i][j] = 0;
      else if(temp[j] == '#') {
        board[i][j] = -1;
        block++;
      }
      else {
        board[i][j] = temp[j] - '0';
        q[board[i][j]].push({{i, j}, 0});
        cnt[board[i][j]]++;
        visited[i][j] = true;
      }
    }
  }
}

bool isEnd() {
  int sum = 0;
  for(int i = 1; i <= P; i++)
    sum += cnt[i];
  if(sum == N * M - block) return true;
  else return false;
}

void BFS(int idx) {
  int sz = q[idx].size();
  while(sz--) {
    auto cur = q[idx].front(); q[idx].pop();
    q[idx].push({cur.X, 0}); // 0번째 방문으로 초기화
  }

  while(!q[idx].empty()) {
    int x = q[idx].front().X.X;
    int y = q[idx].front().X.Y;
    int step = q[idx].front().Y;
    
    if(step == S[idx]) return;

      q[idx].pop();

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(board[nx][ny] != 0 || visited[nx][ny]) continue;

      visited[nx][ny] = true;
      board[nx][ny] = board[x][y];
      cnt[board[nx][ny]]++;
      q[idx].push({{nx, ny}, step + 1});
    }
  }
}

void solve() {
  memset(visited, false, sizeof(visited));
  while (true) {
    bool progress = false;
    for (int i = 1; i <= P; i++) {
      if (!q[i].empty()) {
        BFS(i);
        progress = true;
      }
    }
    if (!progress) break;
  }
  for(int i = 1; i <= P; i++) {
    cout << cnt[i] << ' ';
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