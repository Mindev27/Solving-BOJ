#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll D, P ,Q;

void input() {
  cin >> D >> P >> Q;
}

void solve() {
  if(D % P == 0 || D % Q == 0) {
    cout << D; return;
  }

  // N > M
  ll N = max(P, Q);
  ll M = min(P, Q);
  ll maxN = D / N + 1;
  ll ans = N * maxN;

  for(int i = maxN - 1; i >= 0; i--) {
    ll div = (D - i * N) / M;
    ll R = (D - i * N) % M;
    if(R == 0) { cout << D; return; }
    ll minI = i * N + (div + 1) * M;
    if(ans == minI) {
      cout << ans; return;
    }
    ans = min(ans, minI);
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
