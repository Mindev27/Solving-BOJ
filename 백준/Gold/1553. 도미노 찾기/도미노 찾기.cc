#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int board[10][10];
bool visited[10][10];
bool used[10][10];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

void input() {
  for(int i = 0; i < 8; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < 7; j++) {
      board[i][j] = temp[j] - '0';
    }
  }
  memset(visited, false, sizeof(visited));
  memset(used, false, sizeof(used));
}

int solve(int x, int y) {
  if(x == 8) return 1;

  int cnt = 0;
  int nx = x, ny = y + 1;
  if(ny == 7) { nx = x + 1, ny = 0; }

  if(visited[x][y]) return solve(nx, ny);

  int num1 = board[x][y];
  visited[x][y] = true;
  
  for(int i = 0; i < 2; i++) {
    int mx = x + dx[i];
    int my = y + dy[i];
    int num2 = board[mx][my];

    if(mx < 0 || mx >= 8 || my < 0 || my >= 7) continue;
    if(visited[mx][my] || used[num1][num2]) continue;

    used[num1][num2] =  used[num2][num1] = true;
    visited[mx][my] = true;

    cnt += solve(nx, ny);

    used[num1][num2] =  used[num2][num1] = false;
    visited[mx][my] = false;
  }

  visited[x][y] = false;
  return cnt;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  cout << solve(0, 0);

  return 0;
}
