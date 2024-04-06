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

int N, M;
int coin[25];
ll dp[100001];


void init() {
  memset(coin, 0, sizeof(coin));
  memset(dp, 0, sizeof(dp));
}

void input() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    cin >> coin[i];
  }
  cin >> M;
}

void solve() {
  dp[0] = 1;
  for(int i = 0; i < N; i++) {
    for(int j = coin[i]; j <= M; j++) {
      dp[j] += dp[j - coin[i]];
    }
  }
  cout << dp[M] << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    init();
    input();
    solve();
  }

  return 0;
}