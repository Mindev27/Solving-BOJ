#include <iostream>

using namespace std;

int n, start, result = 100000000;
int board[10][10] = {};
int path[15] = {};
bool visited[15] = {};

void input() {
  cin >> n >> start;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }
}

void findPath(int index, int time) {
  if(index == n){
    result = min(result, time);
    return;
  }

  for(int i = 0; i < n; i++){
    if(!visited[i]){
      visited[i] = true;
      path[index] = i;
      findPath(index + 1, time + board[path[index - 1]][i]);
      visited[i] = false;
    }
  }
}

void solve() {
  // 플로이드 워셜로 각 행성의 최소거리 찾기
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
      }
    }
  }

  // 값 초기화 후 백트래킹 시작
  visited[start] = true;
  path[0] = start;
  findPath(1, 0);
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();

  solve();

  cout << result;

  return 0;
}