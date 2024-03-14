#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int N, K;
int board[105][15] = {};

void input() {
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < 10; j++) {
      board[i][j] = temp[j] - '0';
    }
  }
}

void gravity() {
  for(int j = 0; j < 10; j++) {
    for(int i = N-1; i >= 0; i--) {
      if(board[i][j] == 0) {
        int ni = i-1;
        while(ni >= 0 && board[ni][j] == 0) ni--;
        if(ni >= 0) {
          board[i][j] = board[ni][j];
          board[ni][j] = 0;
        }
      }
    }
  }
}

bool BFS() {
  bool isFind = false;
  bool visited[105][15] = {};
  queue<pii> q;
  vector<pii> temp;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  memset(visited, false, sizeof(visited));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 10; j++) {
      if(board[i][j] != 0) {
        temp.clear();
        q.push({i, j});
        visited[i][j] = true;

        while(!q.empty()) {
          int x = q.front().X;
          int y = q.front().Y;
          q.pop();

          temp.push_back({x, y});

          for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || N <= nx || ny < 0 || 10 <= ny) continue;
            if(visited[nx][ny] || board[nx][ny] != board[x][y]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
          }
        }

        if(temp.size() >= K) {
          for(pii &i : temp)
            board[i.X][i.Y] = 0;
          isFind = true;
        }
      }
    }
  }
  return isFind;
}

void solve() {
  gravity();
  while(BFS()) {
    gravity();
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 10; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}