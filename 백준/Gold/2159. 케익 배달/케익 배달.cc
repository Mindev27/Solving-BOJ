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

const ll INF = 1e18;
const int MAX = 100005;
int N;
pii a[MAX];
ll dp[MAX][5]; // i번째를 j위치로 배달하는 경우
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

void input() {
  cin >> N;
  for(int i = 0; i <= N; i++) {
    cin >> a[i].X >> a[i].Y;
  }
}

ll solve(int index, int dir, int x, int y) {
  if(index == N) return 0;

  ll& ret = dp[index][dir];
  if(ret != -1) return ret;

  ret = INF;
  for(int i = 0; i < 5; i++) {
    ll nx = a[index + 1].X + dx[i];
    ll ny = a[index + 1].Y + dy[i];

    ll dist = abs(nx - x) + abs(ny - y);

    ret = min(ret, dist + solve(index + 1, i, nx, ny));
  }

  return ret;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, a[0].X, a[0].Y);

  return 0;
}