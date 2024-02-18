#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N;
// i번째까지 봤을때 j=0이면 안뛰어넘은 경우, 1이면 뛰어넘은 경우 필요한 제독제의 양
ll dp[100005][2] = {};
vector<pii> a;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
}

void solve() {
  sort(a.begin(), a.end());
  memset(dp, 0, sizeof(dp));

  dp[0][0] = a[0].Y;
  dp[0][1] = 0;

  for(int i = 1; i < N; i++) {
    // 다음까지 거리
    ll nDist = a[i].X - a[i - 1].X;

    // 이번에 뛰어넘는 경우 0 -> 1
    if(i == N - 1) dp[i][1] = dp[i - 1][0];
    else dp[i][1] = dp[i - 1][0] + nDist * i;

    // 이번에 못뛰어넘는 경우 1 -> 1
    dp[i][1] = min(dp[i][1], dp[i - 1][1] + nDist * (i - 1) + a[i].Y);

    // 그냥 가는 경우 0 -> 0
    dp[i][0] = dp[i - 1][0] + nDist * i + a[i].Y;

  }

  ll temp = dp[N - 1][1];

  reverse(a.begin(), a.end());
  memset(dp, 0, sizeof(dp));

  dp[0][0] = a[0].Y;
  dp[0][1] = 0;

  for(int i = 1; i < N; i++) {
    // 다음까지 거리
    ll nDist = a[i - 1].X - a[i].X;

    // 이번에 뛰어넘는 경우 0 -> 1
    if(i == N - 1) dp[i][1] = dp[i - 1][0];
    else dp[i][1] = dp[i - 1][0] + nDist * i;
    
    // 이번에 못뛰어넘는 경우 1 -> 1
    dp[i][1] = min(dp[i][1], dp[i - 1][1] + nDist * (i - 1) + a[i].Y);

    // 그냥 가는 경우 0 -> 0
    dp[i][0] = dp[i - 1][0] + nDist * i + a[i].Y;
  }

  cout << min(temp, dp[N - 1][1]);
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
