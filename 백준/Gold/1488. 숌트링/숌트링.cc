#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

ll a, b, c, d;

void solve() {
  cin >> a >> b >> c >> d;
  if (a < b) { swap(a, b); swap(c, d); }

  if (a == 0 || c == 0) {
    cout << min(b, d);
    return;
  }
  if (b == 0 || d == 0) {
    cout << min(a, c);
    return;
  }

  if (a < b + 1) cout << b * 2;
  else if (a == b + 1) cout << a + b;
  else cout << min((b + 1) * c, a) + b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
