#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<char> fj;
int dp[100005][3][21]; // i번째 게임에서, j 상태를 선택하고, k번 바꿀 때 최대 이길 수 있는 횟수

void input() {
  cin >> N >> K;
  fj.resize(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> fj[i];
}


int win(char fj, int bs) {
  if ((fj == 'H' && bs == 2) || (fj == 'S' && bs == 0) || (fj == 'P' && bs == 1))
    return 1;
  return 0;
}

void solve() {
  memset(dp, 0, sizeof(dp));

  // 첫 번째 게임에 대한 초기 설정
  for (int j = 0; j < 3; j++) {
    dp[1][j][0] = win(fj[1], j);
  }

  for (int i = 2; i <= N; i++) {
    for (int k = 0; k <= K; k++) {
      for (int j = 0; j < 3; j++) {
        // 바꾸지 않는 경우
        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + win(fj[i], j));
        
        // 바꾸는 경우
        if (k == 0) continue;
        for (int l = 0; l < 3; l++) {
          if (l != j) // 다른 상태로 변경
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k - 1] + win(fj[i], j));
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k <= K; k++) {
      ans = max(ans, dp[N][j][k]);
    }
  }

  cout << ans;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
