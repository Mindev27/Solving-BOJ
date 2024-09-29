#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

ll n, k, x, ans;

void solve() {
  cin >> n >> k >> x;
  if (x == 0) {
    ans = n + 1 - 3 * (k - 1);
    cout << ans << '\n';
  }
  else if (x == 1) {
    ans = n - 3 * (k - 1);
    cout << ans << '\n';
  }
  else if (x == 2 || x == 3) {
    ans = n - 1 - 3 * (k - 1);
    cout << ans << '\n';
  }
  else if (x == 4 || x == 5 || x == 6 || x == 7) {
    ans = n - 2 - 3 * (k - 1);
    if (x == 4) ans++;
    cout << ans << '\n';
  }
  else {
    ans = n - 2 - 3 * (k - 1);
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
