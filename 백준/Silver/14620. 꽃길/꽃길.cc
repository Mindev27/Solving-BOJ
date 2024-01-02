#include <iostream>
#include <climits>

using namespace std;

const int SIZE = 15;
int n;
int board[SIZE][SIZE] = {};

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }
}

int calcCost(int a, int b, int c){
  int dx[] = {1, 0 ,-1, 0};
  int dy[] = {0, 1, 0, -1};

  int cost = 0; // 전체 금액
  pair<int, int> flower[3];
  flower[0].first = a / n; flower[0].second = a % n;
  flower[1].first = b / n; flower[1].second = b % n;
  flower[2].first = c / n; flower[2].second = c % n;

  bool visited[SIZE][SIZE] = {};
  for(int i = 0; i < 3; i++) {
    int x = flower[i].first;
    int y = flower[i].second;

    // 수술의 땅값 누적
    if(visited[x][y]) return INT_MAX;
    visited[x][y] = true;
    cost += board[x][y];
    
    for(int j = 0; j < 4; j++){
      int nx = x + dx[j];
      int ny = y + dy[j];

      if(nx < 0 || nx >= n || ny < 0 || ny >= n)
        return INT_MAX;
      
      // 꽃잎의 땅값 누적
      if(visited[nx][ny]) return INT_MAX;
      visited[nx][ny] = true;
      cost += board[nx][ny];
    }
  }

  return cost;
}

void solve() {
  int result = INT_MAX;
  for(int i = 0; i <= n * n; i++){
    for(int j = i + 1; j <= n * n; j++){
      for(int k = j + 1; k <= n * n; k++){
        result = min(result, calcCost(i, j, k));
      }
    }
  }
  cout << result;
}


int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
