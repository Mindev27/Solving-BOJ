#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, B;
int P[15], A[15], C[15];
pll dp[15][30005]; 
// i번째 작업까지 비용 j를 쓸 때 (최대확률, i를 구매하는 개수) 

void input() {
  cin >> N >> B;
  for(int i = 1; i <= N; i++) {
    cin >> P[i] >> A[i] >> C[i];
  }
}

// 확률은 0일때 1, 개수는 0으로 초기화
void init() {
  for(int j = 0; j <= B; j++) {
    dp[0][j] = {1, 0};
  }
}

void solve() {
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= B; j++) {
      for(int k = 0; k <= j / C[i]; k++) { // k대를 추가할 때
        ll curP = P[i] + k * A[i];
        if(curP > 100) curP = 100;  // 확률은 100을 넘을 수 없음
        
        ll curNum = dp[i - 1][j - k * C[i]].X * curP;

        if(curNum > dp[i][j].X) {
          dp[i][j] = {curNum, k};
        }

        if(curP == 100) break; // 더 이상 탐색할 필요없음
      }
    }
  }

  cout << dp[N][B].X << "\n";
  vector<ll> ans(N + 1, 0);
  for (int i = N, j = B; i > 0; --i) {
        ans[i] = dp[i][j].Y;
      j -= dp[i][j].Y * C[i]; // 사용된 비용 감소
  }

  for (int i = 1; i <= N; ++i) {
      cout << ans[i] << ' ';
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  init();
  solve();

  return 0;
}
