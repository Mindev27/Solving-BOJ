#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, K;
char board[2][200005];
int dp[2][200005];

void input() {
  cin >> N >> K;
  for(int i = 0 ; i < 2; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < N; j++) {
      board[i][j] = temp[j];
      board[i][j+N] = temp[j];
    }
  }
  board[0][2*N] = board[0][N];
  board[1][2*N] = board[1][N];
}

void solve() {
  if(board[0][0] == '#' && board[1][0] == '#') { cout << -1; return; }
  if(board[0][N-1] == '#' && board[1][N-1] == '#') { cout << -1; return; }
  memset(dp, -1, sizeof(dp));
  if(board[0][0] != '#') dp[0][0] =  0;
  if(board[1][0] != '#') dp[1][0] =  0;
  for(int j = 1; j <= 2 * N; j++) {
    for(int i = 0; i < 2; i++) {
      if(board[i][j] == '#') continue;
      if(dp[i][j-1] != -1) dp[i][j] = dp[i][j-1] + 1; // 직진

      if(dp[(i+1)%2][j-1] != -1 && (board[i][j-1] != '#' || board[(i+1)%2][j] != '#')) {
        if(dp[i][j] == -1) dp[i][j] = dp[(i+1)%2][j-1] + 2;
        else dp[i][j] = min(dp[i][j], dp[(i+1)%2][j-1] + 2);
      }
    }
  }

  // for(int i = 0; i < 2; i++) {
  //   for(int j = 0; j <= 2 * N; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // 예외 처리
  if(K == 1) {
    if(board[0][N-1] == '#' && board[1][N-1] == '#') {
      cout << -1;
    }
    else if(board[0][N-1] == '#') cout << dp[1][N-1];
    else if(board[1][N-1] == '#') cout << dp[0][N-1];
    else cout << min(dp[0][N-1], dp[1][N-1]);
    return;
  }
  
  bool flag = true;
  if(dp[0][N-1] == -1 && dp[1][N-1] == -1) flag = false;
  if(board[0][0] == '#' && board[1][N-1] == '#') flag = false;
  if(board[1][0] == '#' && board[0][N-1] == '#') flag = false;
  if(flag == false) { cout << -1; return; }

  if(dp[0][2*N-1] == -1) {
    ll ans = dp[1][2*N] - dp[1][N];
    ans *= K - 1;
    ans += dp[1][N-1];
    cout << ans;
    return;
  }
  if(dp[1][2*N-1] == -1) {
    ll ans = dp[0][2*N] - dp[0][N];
    ans *= K - 1;
    ans += dp[0][N-1];
    cout << ans;
    return;
  }

 
  
  if(dp[0][2*N] == -1) {
    ll ans = dp[1][2*N] - dp[1][N];
    ans *= K;
    cout << ans - (dp[1][2*N] - min(dp[0][2*N-1], dp[1][2*N-1]));
    return;
  }

  if(dp[1][2*N] == -1) {
    ll ans = dp[0][2*N] - dp[0][N];
    ans *= K;
    cout << ans - (dp[0][2*N] - min(dp[1][2*N-1], dp[0][2*N-1]));
    return;
  }

  ll ans1 = dp[0][2*N] - dp[0][N];
  ll ans2 = dp[1][2*N] - dp[1][N];
  ans1 *= K - 1;
  ans2 *= K - 1;
  ans1 += dp[0][N-1];
  ans2 += dp[1][N-1];
  cout << min(ans1, ans2);
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
