#include <algorithm>
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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int R, C, N;
char b1[205][205] = {};
char b3[205][205] = {};
char b5[205][205] = {};
bool visited[205][205] = {};

void input() {
  cin >> R >> C >> N;
  for(int i = 0 ; i < R; i++) {
    string temp; cin >> temp;
    for(int j = 0 ; j < C; j++) {
      b1[i][j] = temp[j];
    }
  }
}

// 폭탄에 부서지는곳을 true표시하는 함수
void mark(char arr[][205]) {
  memset(visited, false, sizeof(visited));

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(arr[i][j] == 'O') {
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];

          if(nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;

          visited[nx][ny] = true;
        }
      }

    }
  }
}

// 배열 출력
void printAnswer(char arr[][205]) {
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cout << arr[i][j];
    }
    cout << '\n';
  }
}


void solve() {
  if(N == 1){ printAnswer(b1); return; }
  
  if(N % 2 == 0) { // 짝수면 가득 찬거
    for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        cout << "O";
      }
      cout << '\n';
    }
    return;
  }

  // b3 구하기
  mark(b1);
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(visited[i][j]) b3[i][j] = '.';
      else b3[i][j] = 'O';
    }
  }

  // b5 구하기
  mark(b3);
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(visited[i][j]) b5[i][j] = '.';
      else b5[i][j] = 'O';
    }
  }

  if((N - 1) % 4 == 0) printAnswer(b5);
  else printAnswer(b3);
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