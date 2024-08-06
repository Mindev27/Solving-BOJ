#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
vector<pii> v;
vector<pii> range;

void input() {
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i].X >> v[i].Y;
  }
}

bool check(ll T) {
  vector<pii> ranges(N);
  for (int i = 0; i < N; i++) {
    ll x = v[i].X;
    ll h = v[i].Y;
    ranges[i] = {max(x - h / 2, x - T), min(x + h / 2, x + T)};
  }

  for (int i = 1; i < N; i++) {
    if (ranges[i].X <= ranges[i - 1].Y) {
      return false;
    }
  }
  return true;
}

void solve() {
  sort(v.begin(), v.end());
  ll lo = 0, hi = 2e9 + 5;

  while (lo < hi) {
    ll mid = lo + (hi - lo + 1) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  if (lo >= 2e9 + 5) {
    cout << "forever" << endl;
  } else {
    cout << lo << endl;
  }
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
