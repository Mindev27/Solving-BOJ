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

int N;
int board[55][55] = {};
vector<pair<char, pii>> ans;

void input() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }
}

// sx, sy에서 시작해서 sx를 찾는 함수
pii find(int sx, int sy) {
  //cout << "find : " << sx << ' ' << sy << '\n';
  // 첫줄 탐색
  for(int b = sy + 1; b <= N; b++) {
    if(board[sx][b] == sx)
      return {sx, b};
  }

  // 다음줄 부터 전체 탐색
  for(int a = sx + 1; a <= N; a++) {
    for(int b = 1; b <= N; b++) {
      if(board[a][b] == sx)
        return {a, b};
    }
  }
  return {-1, -1}; // 못찾을일이 없긴함 ㅋㅋ
}

// 칸을 움직임
void move(char cmd, int line, int cnt) {
  ans.push_back({cmd, {line, cnt}});

  if(cmd == 'R') {
    int row[55] = {};
    for(int j = 1; j <= N; j++) // 복사
      row[j] = board[line][j];

    // cnt 만큼 오른쪽으로 밀고 넣기
    for(int j = 1; j <= N; j++)
      board[line][j] = row[(j - cnt - 1 + N) % N + 1];
  }

  if(cmd == 'D') {
      int col[55] = {};
      for(int i = 1; i <= N; i++) // 복사
        col[i] = board[i][line];

      // cnt 만큼 아래로 밀고 넣기
      for(int i = 1; i <= N; i++)
        board[i][line] = col[(i - cnt - 1 + N) % N + 1];
  }
}

// x, y칸을 key로 맞추기
void fit(int x, int y, pii key) {
  int kx = key.X, ky = key.Y;
  // cout << x << ' ' << y << ' ' << kx << ' ' << ky << '\n';

  if(ky == y) { // 같은 열이면
    move('R', kx, 1); // 오른쪽 1칸
    move('D', y, kx - x); // 행 맞추고
    move('R', kx, N - 1); // 왼쪽 1칸
    move('D', y, N - (kx - x)); // 원상복구
    return;
  }

  // 바꿀 행을 찾고 열을 내리기
  int changeRow = max(x, kx) == x ? x + 1 : max(x, kx);
  if(x < changeRow)
    move('D', y, changeRow - x);
  if(kx < changeRow)
    move('D', ky, changeRow - kx);

  // ky를 y에 두기
  move('R', changeRow, (y - ky + N) % N);

  // 각 열을 원래자리로 두기
  if(x < changeRow)
    move('D', y, N - (changeRow - x));
  if(kx < changeRow)
    move('D', ky, N - (changeRow - kx));
}

void check() {
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

// 한칸씩 탐색하며 칸을 맞추기(마지막행은 자동으로 맞춰짐)
void solve() {
  for(int i = 1; i <= N - 1; i++) {
    for(int j = 1; j <= N; j++) {
      if(board[i][j] != i){
        // 이후칸중에서 열에 맞는 숫자 찾기
        pii key = find(i, j);
        fit(i, j, key);
        // check();
      }
    }
  }

  cout << ans.size() << '\n';
  for(auto &i: ans)
    cout << i.X << ' ' << i.Y.X << ' ' << i.Y.Y << '\n';
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