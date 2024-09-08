#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
vector<ll> a, b;

// k가 제곱수인지 확인
bool check(ll k) {
  ll sqrtK = sqrt(k);
  if (sqrtK * sqrtK == k) return true;
  return false;
}

void solve() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    ll x; cin >> x;
    a.push_back(x);
    b.push_back(x);
  }

  sort(b.begin(), b.end());

  // Ai Bi가 거듭제곱인지 확인하기
  bool flag = true;
  for(int i = 0; i < N; i++) {
    ll gcd = __gcd(a[i], b[i]);
    ll x = a[i] / gcd;
    ll y = b[i] / gcd;

    if(!(check(x) && check(y))) {
      flag = false;
      break;
    }
  }

  cout << (flag ? "YES" : "NO");
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}

