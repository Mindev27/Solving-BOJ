#include <iostream>

using namespace std;

int n;
int dp[25][105] = {}; // dp[i][j] = k : i번째까지 봤을때 체력이 j이라면 그때의 최대기쁨이 k이다.
int health[25] = {};    // 체력
int joy[25] = {};       // 기쁨

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++)    // 체력 입력
    cin >> health[i];

  for(int i = 1; i <= n; i++)    // 기쁨 입력
    cin >> joy[i];
}

void solve() {
  for(int i = 1; i <= n; i++) {          // 총 n명의 사람을 볼 때
    for(int j = 100; j >= 0; j--){      // 거꾸로 확인하여 중복 계산을 피함
      if(j - health[i] >= 1)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - health[i]] + joy[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[n][100];
}

int main() {
  // c++의 입출력은 printf, scanf보다 느려서 다음 코드르 사용하여 빠르게 만듭니다
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input(); // 입력
  solve(); // 풀기

  return 0;
}