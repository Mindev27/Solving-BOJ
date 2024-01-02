#include <iostream>
#include <vector>

using namespace std;

int main() {
  int board[3] = {};
  vector<pair<int, int>> dp; // 최대, 최소 저장
  
  int n; cin >> n;
  int a, b, c;
  
  cin >> a >> b >> c;
  dp.push_back({a, a});
  dp.push_back({b, b});
  dp.push_back({c, c});

  for(int i = 1; i < n; i++){
    cin >> board[0] >> board[1] >> board[2];

    // 최대값 계산
    int max0 = max(dp[0].first, dp[1].first) + board[0];
    int max1 = max(dp[0].first, max(dp[1].first, dp[2].first)) + board[1];
    int max2 = max(dp[1].first, dp[2].first) + board[2];

    // 값 업데이트
    dp[0].first = max0;
    dp[1].first = max1;
    dp[2].first = max2;
    
    // 최소값 계산
    int min0 = min(dp[0].second, dp[1].second) + board[0];
    int min1 = min(dp[0].second, min(dp[1].second, dp[2].second)) + board[1];
    int min2 = min(dp[1].second, dp[2].second) + board[2];
    
    // 값 업데이트
    dp[0].second = min0;
    dp[1].second = min1;
    dp[2].second = min2;
  }

  // 최대 최소 출력
  cout << max(dp[0].first, max(dp[1].first, dp[2].first)) << ' ';
  cout << min(dp[0].second, min(dp[1].second, dp[2].second));
}