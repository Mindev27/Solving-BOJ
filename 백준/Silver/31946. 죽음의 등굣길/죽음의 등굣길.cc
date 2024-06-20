#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M, D;
int board[105][105];

void input() {
  cin >> N >> M;
  for (int i = 0 ; i < N; i++) {
    for(int j = 0 ; j < M; j++) {
      cin >> board[i][j];
    }
  }
  cin >> D;
}

int dist(int a, int b, int c, int d) {
  return abs(a - c) + abs(b - d);
}

void solve() {
  if(board[0][0] != board[N - 1][M - 1]) {
    cout << "DEAD";
    return;
  }

  int key = board[0][0];

  queue<pii> q;
  bool visited[105][105];
  memset(visited, false, sizeof(visited));
  q.push({0, 0});
  visited[0][0] = true;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();
    
    if(x == N - 1 && y == M - 1) {
      cout << "ALIVE"; return;
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(visited[i][j] || board[i][j] != key || dist(i, j, x, y) > D)
          continue;

        visited[i][j] = true;
        q.push({i, j});
      }
    }
  }
  cout << "DEAD";
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
