#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int R, C;
vector<pii> wolf;
char board[505][505];

void input() {
  cin >> R >> C;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> board[i][j];
      if(board[i][j] == 'W')
        wolf.push_back({i, j});
    }
  }
}

void solve() {
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  
  for(auto &i : wolf){
    for(int j = 0; j < 4; j++){
      int nx = i.X + dx[j];
      int ny = i.Y + dy[j];

      if(nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;

      if(board[nx][ny] == 'S'){ cout << 0; return; }
    }
  }

  cout << "1\n";
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(board[i][j] == '.') cout << 'D';
      else cout << board[i][j];
    }
    cout << '\n';
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
