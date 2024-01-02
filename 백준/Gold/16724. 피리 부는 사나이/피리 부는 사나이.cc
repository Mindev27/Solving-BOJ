#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000005;
int row, col;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[1005][1005] = {};
int parent[MAX] = {};

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y) parent[x] = y;
  else parent[y] = x;
}

bool findParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x == y) return true;
  else return false;
}

void input() {
  cin >> row >> col;
  for(int i = 0; i < row; ++i) {
    string temp; cin >> temp;
    for(int j = 0; j < col; ++j){
      switch(temp[j]){
        case 'D':
          board[i][j] = 0;
          break;
        case 'U':
          board[i][j] = 1;
          break;
        case 'R':
          board[i][j] = 2;
          break;
        case 'L':
          board[i][j] = 3;
          break;
      }
    }
  }

  // parent 배열 초기화
  for(int i = 0; i < MAX; ++i)
    parent[i] = i;
}

void solve() {
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < col; ++j) {
      int nx = i + dx[board[i][j]];
      int ny = j + dy[board[i][j]];

      int curNum = i * col + j;
      int nextNum = nx * col + ny;

      unionParent(curNum, nextNum);
    }
  }

  int result = 0;
  bool answer[MAX] = {};
  for(int i = 0; i < row * col; ++i) {
    int curParent = getParent(i);
    if(!answer[curParent]){
      answer[curParent] = true;
      result++;
    }
  }

  cout << result;
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
