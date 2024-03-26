#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N;
vector<ll> p;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    ll x; cin >> x;
    p.push_back(x);
  }
}

void solve() {
  ll grundy = 0;
  for(ll &i : p) {
    grundy ^= i;
  }

  if(grundy) cout << "koosaga";
  else cout << "cubelover";
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
