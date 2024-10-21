#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M, block = 0, ans = 0;
vector<pair<pii, int>> cctv;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int calc(int board[][10]) {
  int x = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 7) x++;
    }
  }
  return x;
}

void paint(int board[][10], pii pos, int i) {
  pii dir = { dx[i], dy[i] };
  while (true) {
    pos.X += dir.X;
    pos.Y += dir.Y;

    if (pos.X < 0 || pos.X >= N || pos.Y < 0 || pos.Y >= M)
      break;

    if (board[pos.X][pos.Y] == 6) break;
    if (board[pos.X][pos.Y] == 0) board[pos.X][pos.Y] = 7;
  }
}

void backTrack(int board[][10], int idx) {
  if (idx == cctv.size()) {
    ans = max(ans, calc(board));
    return;
  }

  pii pos = cctv[idx].X;

  // i번째의 타입에 따라 색칠
  if (cctv[idx].Y == 1) {
    for (int i = 0; i < 4; i++) {
      int tempBoard[10][10];
      memcpy(tempBoard, board, sizeof(tempBoard));
      // 색칠
      paint(tempBoard, pos, i);

      backTrack(tempBoard, idx + 1);
    }
  }
  else if (cctv[idx].Y == 2) {
    for (int i = 0; i < 4; i++) {
      int tempBoard[10][10];
      memcpy(tempBoard, board, sizeof(tempBoard));
      // 색칠
      paint(tempBoard, pos, i);
      paint(tempBoard, pos, (i + 2) % 4);

      backTrack(tempBoard, idx + 1);
    }
  }
  else if (cctv[idx].Y == 3) {
    for (int i = 0; i < 4; i++) {
      int tempBoard[10][10];
      memcpy(tempBoard, board, sizeof(tempBoard));
      // 색칠
      paint(tempBoard, pos, i);
      paint(tempBoard, pos, (i + 1) % 4);

      backTrack(tempBoard, idx + 1);
    }
  }
  else if (cctv[idx].Y == 4) {
    for (int i = 0; i < 4; i++) {
      int tempBoard[10][10];
      memcpy(tempBoard, board, sizeof(tempBoard));
      // 색칠
      paint(tempBoard, pos, i);
      paint(tempBoard, pos, (i + 1) % 4);
      paint(tempBoard, pos, (i + 2) % 4);

      backTrack(tempBoard, idx + 1);
    }
  }
  else if (cctv[idx].Y == 5) {
    int tempBoard[10][10];
    memcpy(tempBoard, board, sizeof(tempBoard));
    for (int i = 0; i < 4; i++) {
      // 색칠
      paint(tempBoard, pos, i);
    }
    backTrack(tempBoard, idx + 1);
  }
}

void solve() {
  int board[10][10];
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 6) {
        block++;
      }
      if (board[i][j] != 0 && board[i][j] != 6) {
        cctv.push_back({ {i, j}, board[i][j] });
      }
    }
  }

  backTrack(board, 0);

  cout << N * M - block - (int)cctv.size() - ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
