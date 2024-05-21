#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N, M;
ll a[100005];

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
}

void solve() {
  sort(a, a + N);

  ll ans = 1e18;
  int l = 0, r = 0;
  while (l < N) {
    while (r < N && a[r] - a[l] < M) r++;
    if (r == N) break;
    ans = min(ans, a[r] - a[l]);
    l++;
    if (l == r) r++;
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
