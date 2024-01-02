#include <iostream>
#include <vector>

using namespace std;

int main() {
  int dp[101][10001] = {};
  vector<int> byte;
  vector<int> cost;
  int n, m;
  cin >> n >> m;

  byte.push_back(0); // 인덱스를 맞추기 위함
  cost.push_back(0);
  
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    byte.push_back(a);
  }
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    cost.push_back(a);
  }

  //bottom-up
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= 10000; j++){
      if(j - cost[i] >= 0)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + byte[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  //탐색하면서 필요바이트 수 이상이 될때 출력
  for(int i = 0; i <= 10000; i++){
    if(dp[n][i] >= m){
      cout << i;
      break;
    }
  }
}