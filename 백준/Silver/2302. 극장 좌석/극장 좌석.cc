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
ll dp[50];
int vip[50];

void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    cin >> vip[i];
  }
}

void solve() {
  dp[0] = dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= N; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

  ll ans = 1;
  int cur = 0;
  for(int i = 0; i < M; i++) {
    int next = vip[i];
    ans = dp[next - cur -1] * ans;
    cur = next;
  }
  cout << ans * dp[N - cur];
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