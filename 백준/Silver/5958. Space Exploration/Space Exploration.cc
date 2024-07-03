#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
int board[1005][1005];
bool visited[1005][1005];

void input() {
  cin >> N;
  for(int i = 0; i < N ;i++) {
    string s; cin >> s;
    for(int j = 0; j < N; j++) {
      board[i][j] = s[j];
    }
  }
}

void BFS(int a, int b) {
  queue<pii> q;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  
  visited[a][b] = true;
  q.push({a, b});

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if(board[nx][ny] == '*' && !visited[nx][ny]) {
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

void solve() {
  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(!visited[i][j] && board[i][j] == '*') {
        BFS(i, j);
        ans++;
      }
    }
  }

  cout << ans;
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