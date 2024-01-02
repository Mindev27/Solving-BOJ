#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int SIZE = 101;
int startX, startY; // 시작 위치
int row, col, volcanoNum;
int board[SIZE][SIZE];
int vol[SIZE][SIZE];
bool visited[SIZE][SIZE] = {};
vector<pair<int, pair<int, int>>> volcano; // 시간, x, y 좌표 저장

void input();
void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  input(); // 입력

  // 화산이 폭발하는 순서대로 정렬
  sort(volcano.begin(), volcano.end());

  solve();
}

void input() {
  cin >> row >> col >> volcanoNum;
  cin >> startX >> startY;

  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= col; j++) {
      cin >> board[i][j];
      vol[i][j] = INT_MAX;
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < volcanoNum; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    volcano.push_back({t, {x, y}});
  }
}

void solve() {
  // 시간, x, y 좌표 (1: 사람, 0: 화산쇄설류)
  queue<pair<int, pair<int, int>>> q;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  // 화산이 퍼질때 최단거리 업데이트
  for(auto temp : volcano){
    q.push(temp);
  }

  while (!q.empty()) {
    int curTime = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx <= 0 || row < nx || ny <= 0 || col < ny)
        continue;

      if(curTime + 1 < vol[nx][ny]){
        vol[nx][ny] = curTime + 1;
        q.push({curTime + 1, {nx, ny}});
      }
    }
  }


  // 원래 화산위치를 표시, 0이면 지나갈수 없다
  for(int i = 0; i < volcanoNum; i++){
    auto iter = volcano[i];
    vol[iter.second.first][iter.second.second] = 0;
  }

  // 시간을 비교하며 재성이가 갈수있는 칸을 탐색
  q.push({0, {startX, startY}});
  int maxHeight = 0;
  int Dist = 0;

  while (!q.empty()) {
    int curTime = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    visited[x][y] = true;
    q.pop();

    
    if(maxHeight < board[x][y]){
      maxHeight = board[x][y];
      Dist = curTime;
    }

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx <= 0 || row < nx || ny <= 0 || col < ny)
        continue;

      if(curTime + 1 < vol[nx][ny] && !visited[nx][ny]){
        q.push({curTime + 1, {nx, ny}});
      }
    }
  }

  cout << maxHeight << ' ' << Dist;
}