#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int a, b, ans = 0;

void dfs(ll num) {
  if (num > b) return;
  if (num >= a && num <= b) ans++;

  dfs(num * 10 + 4);
  dfs(num * 10 + 7);
}

void solve() {
  cin >> a >> b;
  dfs(0);

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
