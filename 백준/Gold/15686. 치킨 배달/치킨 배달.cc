#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef struct {
  int x;
  int y;
} POINT;

const int SIZE = 55;
int n, m, answer = INT_MAX;
int board[SIZE][SIZE] = {};
vector<POINT> chicken;      // 치킨집의 정보
vector<bool> visited;       // 치킨집 선택 여부
vector<POINT> house;        // 집의 정보

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int a; cin >> a;
      board[i][j] = a;
      if(a == 1) house.push_back({i,j});
      if(a == 2){
        chicken.push_back({i,j});
        visited.push_back(false); // 치킨집 개수에 맞게 방문정보 배열 넣기
      }
    }
  }
}

// 치킨거리를 계산하고 답에 업데이트하는 함수
int calculateDist() {
  int result = 0;
  
  // 각 집에대해서 어디 치킨집이 가장 가까운지 계산 후 더하기
  for(int i = 0; i < house.size(); i++) {
    int minDist = INT_MAX;
    
    for(int j = 0; j < chicken.size(); j++) {
      if(visited[j]){
        int dist = abs(chicken[j].x - house[i].x)
                    + abs(chicken[j].y - house[i].y);
        minDist = min(minDist, dist);
      }
    }
    result += minDist; // 그 집에 대한 최단 치킨거리 누적
  }

  return result;
}

// 치킨집의 m개의 조합을 모두 찾아서 계산
void solve(int index, int depth) {
  if(depth == m){
    answer = min(answer,calculateDist());
  }
  else{
    for(int i = index; i < chicken.size(); i++){
      if(!visited[i]){
        visited[i] = true;
        solve(i, depth + 1);
        visited[i] = false;
      }
    }
  }
}
int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  input();
  solve(0, 0);
  cout << answer;

  return 0;
}