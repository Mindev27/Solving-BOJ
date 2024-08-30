#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>


ll N;
vector<ll> v;

ll GCD(ll x, ll y) {
  if (y == 0) return x;
  return GCD(y, x % y);
}

void solve() {
  cin >> N;
  v.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  ll gcd = v[1] - v[0];
  for(int i = 0; i < N - 1; i++) {
    gcd = GCD(gcd, v[i + 1] - v[i]);
  }

  vector<ll> ans;
  for(int i = 2; i * i <= gcd; i++) {
    if (gcd % i == 0) {
      if(i * i == gcd) {
        ans.push_back(i);
        continue;
      }
      ans.push_back(i);
      ans.push_back(gcd / i);
    }
  }
  ans.push_back(gcd);
  
  sort(ans.begin(), ans.end());
  for(ll i : ans) {
    cout << i << " ";
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
