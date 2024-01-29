#include <iostream>
#define ll long long

using namespace std;

const ll MOD = 1'000'000'007;
ll N;
ll dp[105][15][10];
// dp[i][j][k] = i번째까지 봤을때, 마지막이 j이고 증감이 k이다.
// 1 : 2번 감소, 2: 1번 감소, 3: 증감X, 4: 1번 증가, 5: 2번 증가

void solve() {
  for(int i = 0; i <= 9; i++) // i로 시작할떄 dp 초기화
    dp[1][i][3] = 1;

  for(int i = 2; i <= N; i++) {   // N자리까지 dp돌리기
    for(int j = 0; j <= 9; j++) { // 마지막 자리 숫자
      if(j == 0) {
        // 1번 감소 -> 2번 감소
        dp[i][j][1] = (dp[i][j][1] + dp[i-1][j+1][2]) % MOD;
        
        // 증감X, 1번 증가, 2번 증가 -> 1번 감소
        dp[i][j][2] = (dp[i][j][2] + dp[i-1][j+1][3] 
                      + dp[i-1][j+1][4] + dp[i-1][j+1][5]) % MOD;
      }

      else if(j == 9) {
        // 1번 증가 -> 2번 증가
        dp[i][j][5] = (dp[i][j][5] + dp[i-1][j-1][4]) % MOD;

        // 증감X, 1번 감소, 2번 감소 -> 1번 증가
        dp[i][j][4] = (dp[i][j][4] + dp[i-1][j-1][3]
                      + dp[i-1][j-1][2] + dp[i-1][j-1][1]) % MOD; 
      }

      else {
        // 1번 감소 -> 2번 감소
        dp[i][j][1] = (dp[i][j][1] + dp[i-1][j+1][2]) % MOD;
        // 증감X, 1번 증가, 2번 증가 -> 1번 감소
        dp[i][j][2] = (dp[i][j][2] + dp[i-1][j+1][3] 
                      + dp[i-1][j+1][4] + dp[i-1][j+1][5]) % MOD;
        
        // 1번 증가 -> 2번 증가
        dp[i][j][5] = (dp[i][j][5] + dp[i-1][j-1][4]) % MOD;
        // 증감X, 1번 감소, 2번 감소 -> 1번 증가
        dp[i][j][4] = (dp[i][j][4] + dp[i-1][j-1][3]
                      + dp[i-1][j-1][2] + dp[i-1][j-1][1]) % MOD; 
      }
    }
  }
  
  ll result = 0;
  for(int j = 0; j <= 9; j++) {
    for(int k = 1; k <= 5; k++) {
      result = (result + dp[N][j][k]) % MOD;
    }
  }

  cout << result;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  solve();

  return 0;
}
