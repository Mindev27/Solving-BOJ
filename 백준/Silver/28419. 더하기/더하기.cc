#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

ll N, a = 0, b = 0;

void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (i % 2 == 0) a += x;
    else b += x;
  }

  if (N == 3) {
    if (b < a) { cout << "-1\n"; }
    else {
      cout << b - a << '\n';
    }
    return;
  }

  cout << max(a, b) - min(a, b) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
