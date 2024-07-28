#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, Q, ice = 0;
int board[100][100];
vector<int> query;
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
  cin >> N >> Q;
  N = 1 << N;
  for(int i = 0 ; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> board[i][j];
      ice += board[i][j];
    }
  }
  for(int i = 0; i < Q; i++) {
    int x; cin >> x;
    query.push_back(x);
  }
}

// board의 x, y부터 n크기의 사각형 시계방향 90도 회전
void rotate(int x, int y, int n) {
  if(n == 1) return;
  vector<vector<int>> temp(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][j] = board[x + i][y + j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[x+i][y+j] = temp[n-j-1][i];
    }
  }
}

void check() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

void melt() {
  int nextBoard[100][100];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      nextBoard[i][j] = board[i][j];
      if(board[i][j] == 0) continue;
      
      int cnt = 0;
      for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(board[nx][ny] > 0) cnt++;
      }

      if(cnt < 3) {
        nextBoard[i][j] = board[i][j] - 1;
        ice--;
      }
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      board[i][j] = nextBoard[i][j];
    }
  }
}

int BFS(int a, int b) {
  queue<pii> q;
  visited[a][b] = true;
  q.push({a, b});
  int result = 0;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();
    result++;

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if(board[nx][ny] == 0 || visited[nx][ny]) continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  return result;
}

void solve() {
  for(int &q : query) {
    q = 1 << q;
    for(int i = 0; i < N; i += q) {
      for(int j = 0; j < N; j += q) {
        rotate(i, j, q);
      }
    }
    melt();
  }

  int maxSize = 0;
  memset(visited, false, sizeof(visited));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(!visited[i][j] && board[i][j] != 0) {
        maxSize = max(maxSize, BFS(i, j));
      }
    }
  }

  cout << ice << '\n';
  cout << maxSize << '\n';
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
