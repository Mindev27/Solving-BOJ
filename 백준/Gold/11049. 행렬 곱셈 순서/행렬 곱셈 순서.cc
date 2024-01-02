#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<pair<int, int>> matrix;
pair<int, int> dpMatrixSize[505][505]; // 행렬 크기 
int dp[505][505] = {};

void input() {
  cin >> N;
  matrix.push_back({0, 0});
  for(int i = 1; i <= N; i++){
    int a, b;
    cin >> a >> b;
    matrix.push_back({a, b});
    dpMatrixSize[i][i] = {a, b};
  }
}

void solve() {
  for(int i = 1; i <= N; i++){
    for(int x = 1; x + i <= N; x++){
      int y = x + i;
      dp[x][y] = INT_MAX;
      
      for(int mid = x; mid < y; mid++){
        dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y]
                        + dpMatrixSize[x][mid].first
                        * dpMatrixSize[x][mid].second 
                        * dpMatrixSize[mid + 1][y].second);
      }

      dpMatrixSize[x][y] = {matrix[x].first, matrix[y].second};
    }
  }

  cout << dp[1][N];
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  input();
  solve();

  return 0;
}