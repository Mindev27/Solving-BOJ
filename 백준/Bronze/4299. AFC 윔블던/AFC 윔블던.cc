#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int x, y;

void input() {
  cin >> x >> y;
}

void solve() {
  if(x < y || (x + y) % 2 == 1 || (x - y) % 2 == 1) { cout << -1; return; }
  cout << (x + y) / 2 << ' ' << (x - y) / 2;
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
