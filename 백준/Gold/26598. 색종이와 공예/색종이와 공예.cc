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

int N, M, rowMax, colMax;
char board[1005][1005];
bool visited[1005][1005];

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
    }
  }
}

int BFS(int a, int b) {
  queue<pii> q;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  
  int cnt = 1; // 칸의 개수
  char color = board[a][b];
  rowMax = a, colMax = b;

  q.push({a, b});
  visited[a][b] = true;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    rowMax = max(rowMax, x);
    colMax = max(colMax, y);

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;

      if(!visited[nx][ny] && board[nx][ny] == color){
        visited[nx][ny] = true;
        q.push({nx, ny});
        cnt++;
      }
    }
  }

  return cnt;
}

void solve() {
  memset(visited, false, sizeof(visited));
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(visited[i][j]) continue;
      
      int cnt = BFS(i, j); // BFS 칸수 세기

      // 직사각형 모양이 아니면 바보
      if(cnt != (rowMax - i + 1) * (colMax - j + 1)){
        cout << "BaboBabo";
        return;
      }
    }
  }

  cout << "dd";
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
