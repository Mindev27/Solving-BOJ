#include <iostream>

using namespace std;

int main() {
  int box[1001] = {};
  int dp[1001] = {};
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> box[i];
    dp[i] = 1;
  }

  if(box[2] > box[1]) dp[2] = 2;
  else dp[2] = 1;

  for(int i = 3; i <= n; i++){
    for(int j = 1; j < i; j++){
      if(box[i] > box[j])
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }

  int result = 0;

  for(int i = 1; i <= n; i++){
    result = max(result, dp[i]);
  }

  cout << result;
}