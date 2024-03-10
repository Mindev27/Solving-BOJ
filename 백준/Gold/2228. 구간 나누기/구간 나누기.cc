#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MAX = 105;
const int INF = 0x3f3f3f3f;
int N, M;
int num[MAX];
int dp[MAX][MAX]; // 1~i까지 j개의 구간을 택할때 최댓값

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> num[i];
  }
}

int dfs(int n, int m) {
  if(m == 0) return 0;
  if(n <= 0) return -INF; // 가장 작은 값 반환
  if(dp[n][m] != -1)      // 메모이제이션
    return dp[n][m];

  int ret = 0;
  dp[n][m] = dfs(n - 1, m);
  for(int i = n; i > 0; i--) {
    ret += num[i]; // 구간합 계산
    dp[n][m] = max(dp[n][m], ret + dfs(i - 2, m - 1));
  }

  return dp[n][m];
}
void solve() {
  memset(dp, -1, sizeof(dp));
  cout << dfs(N, M);
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