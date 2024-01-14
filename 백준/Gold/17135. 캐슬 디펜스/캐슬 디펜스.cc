#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

#define ll long long

using namespace std;

const int INF = 999'999'999;
int N, M, D;
int board[20][20] = {};

void input() {
  cin >> N >> M >> D;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
}

// 맨해튼 거리 계산
int getDist(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int calc(int a, int b, int c) {
  int copy[25][25];
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      copy[i][j] = board[i][j];

  vector<pair<int, int>> ans;
  vector<int> arc;
  arc.push_back(a);
  arc.push_back(b);
  arc.push_back(c);

  int result = 0;
  for(int wave = 0; wave < N; wave++) {
    ans.clear();
    for(int pos : arc){
      int minDist = INF;
      int minCol = INF;
      int minRow = INF;

      // 보드에서 가장 가까우면서 왼쪽에 있는 적 찾기
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
          if(copy[i][j] == 0) continue;
          
          int curDist = getDist(i, j, N, pos);
          if(minDist > curDist){
            minDist = curDist;
            minRow = i;
            minCol = j;
          }
          else if(minDist == curDist && minCol > j){
            minRow = i;
            minCol = j;
          }
        }
      }

      // 후보에 넣기
      if(minDist <= D)
        ans.push_back({minRow, minCol});
    }

    for(int i = 0; i < ans.size(); i++){
      if(copy[ans[i].first][ans[i].second] == 1){
        result++;
        copy[ans[i].first][ans[i].second] = 0;
      }
    }

    // 보드 밀기
    for(int j = 0; j < M; j++)
      copy[N - 1][j] = 0;
    for(int i = N - 1; i > 0; i--) {
      for(int j = 0; j < M; j++) {
        copy[i][j] = copy[i - 1][j];
      }
    }
    for(int j = 0; j < M; j++)
      copy[0][j] = 0;
  }

  return result;
}

void solve() {
  int result = 0;

  // 가능한 모든 궁수위치 조합 계산
  for(int i = 0; i < M; i++) {
    for(int j = i + 1; j < M; j++) {
      for(int k = j + 1; k < M; k++) {
        result = max(result, calc(i, j, k));
      }
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