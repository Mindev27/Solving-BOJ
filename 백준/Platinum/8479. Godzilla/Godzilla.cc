#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N, M;
vector<ll> a;

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    ll x; cin >> x;
    a.push_back(x);
  }
}

void solve() {
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    ans += a[i] - i > 0 ? a[i] - i : 0;
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
