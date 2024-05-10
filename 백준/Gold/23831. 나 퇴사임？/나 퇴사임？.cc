#include <iostream>
#include <map>
#include <string>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int INF = 999999999;
const int MAX = 105;
int N, A, B;
struct mood {
  int p, q, r, s;
};
vector<mood> day;
int dp[MAX][MAX][MAX][2];

void input() {
  cin >> N >> A >> B;
  day.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> day[i].p >> day[i].q >> day[i].r >> day[i].s;
  }
}

void init() {
  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      for(int k = 0; k < MAX; k++)
        for(int x = 0; x < 2; x++)
          dp[i][j][k][x] = -INF;
}

void solve() {
  init();
  dp[1][1][0][0] = max(day[1].p, day[1].q);
  dp[1][0][0][1] = day[1].r;
  dp[1][0][1][0] = day[1].s;

  for(int i = 2; i <= N; i++) {
    for(int j = 1; j <= i; j++) {
      for(int k = 0; k <= j; k++) {
        if(j == k) 
          dp[i][k][j-k][0] = max(dp[i-1][k-1][j-k][1], dp[i-1][k-1][j-k][0]) + max(day[i].p, day[i].q);
          
        else if(k == 0)
          dp[i][k][j-k][0] = max(dp[i-1][k][j-k-1][1], dp[i-1][k][j-k-1][0]) + day[i].s;

        else {
          int ret = -INF;
          ret = max(ret, dp[i-1][k-1][j-k][0] + max(day[i].p, day[i].q));
          ret = max(ret, dp[i-1][k-1][j-k][1] + max(day[i].p, day[i].q));
          ret = max(ret, dp[i-1][k][j-k-1][0] + day[i].s);
          ret = max(ret, dp[i-1][k][j-k-1][1] + day[i].s);
          dp[i][k][j-k][0] = ret;
        }
        dp[i][k][j-k][1] = dp[i-1][k][j-k][0] + day[i].r;
      }
    }
  }

  int result = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= i; j++) {
      for(int k = 0; k <= j; k++) {
        if(j - k <= A && k >= B) {
          result = max(result, dp[i][k][j-k][0]);
          result = max(result, dp[i][k][j-k][1]);
        }
      }
    }
  }

  cout << result;
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