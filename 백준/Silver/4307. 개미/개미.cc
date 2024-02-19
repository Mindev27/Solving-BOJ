#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N, L;

void input() {
  cin >> L >> N;
}

void solve() {
  ll minTime = 0, maxTime = 0;
  for(int i = 0; i < N; i++) {
    ll x; cin >> x;
    minTime = max(minTime, min(x, L - x));
    maxTime = max(maxTime, max(x, L - x));
  }
  cout << minTime << ' ' << maxTime << "\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    input();
    solve();
  }

  return 0;
}