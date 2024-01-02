#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int map[100000][2];
  int dp[100000][2];
  int testCase;
  
  cin >> testCase;

  for(int t = 0; t < testCase; t++){
    int n;
    cin >> n;

    // 입력
    for(int i = 0; i < n; i++)
      cin >> map[i][0];
    for(int i = 0; i < n; i++)
      cin >> map[i][1];

    // dp 초기값 설정
    dp[0][0] = map[0][0];
    dp[0][1] = map[0][1];
    dp[1][0] = map[1][0] + map[0][1];
    dp[1][1] = map[1][1] + map[0][0];

    // dp 계산
    for(int i = 2; i < n; i++){
      dp[i][0] = max(dp[i-2][0], max(dp[i-2][1], dp[i-1][1])) + map[i][0];
      dp[i][1] = max(dp[i-2][1], max(dp[i-2][0], dp[i-1][0])) + map[i][1];
    }

    int result = max(dp[n-1][0], dp[n-1][1]);
    cout << result << "\n";
  }
}