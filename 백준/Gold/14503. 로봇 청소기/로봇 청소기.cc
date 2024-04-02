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

int N, M, dir;
pii p;
int board[55][55] = {};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
  cin >> N >> M;
  cin >> p.X >> p.Y >> dir;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
}

// 4방향이 모두 깨끗한지 확인
bool isClear(int a, int b) {
  for(int i = 0; i < 4; i++) {
    int x = a + dx[i];
    int y = b + dy[i];
    if(board[x][y] == 0)
      return false;
  }
  return true;
}

bool isValid(pii cur) {
  if(cur.X < 0 || cur.X >= N || cur.Y < 0 || cur.Y >= M)
    return false;
  return true;
}

// 0:더러운 칸 1:벽 2:청소된 칸
void solve() {
  int ans = 0;
  while(true) {
    if(board[p.X][p.Y] == 0) {
      board[p.X][p.Y] = 2;  // 현재 위치 청소
      ans++;
    }
    
    if(isClear(p.X, p.Y)) { //주변이 모두 깨끗하다면
      pii back = {p.X + dx[(dir + 2) % 4], p.Y + dy[(dir + 2) % 4]};
      if(!isValid(back)) break;
      if(board[back.X][back.Y] == 1) // 뒤가 벽이라면 끝
        break;
      else {
        p = back;
        continue;
      }
    }

    else { // 주변중에 더러운 곳이 있다면
      bool isFind = false;
      for(int i = 0 ; i < 4; i++) {
        dir = (4 + dir - 1) % 4; // 반시계 회전
        pii front = {p.X + dx[dir], p.Y + dy[dir]};
        if(!isValid(front)) continue;
        if(board[front.X][front.Y] == 0) {
          p = front;
          isFind = true;
          break;
        }
      }

      if(isFind == false) break;
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