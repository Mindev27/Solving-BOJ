#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
vector<ll> v;

void input() {
  cin >> N;
  v.resize(N+1, 0);
  for(int i = 1; i <= N; i++) {
    cin >> v[i];
  }
}

void solve() {
  for(int i = 1; i <= N; i++) {
    v[i] += v[i - 1];
  }

  ll minK = -1, minVal = 1e18;
  for(int k = N / 2; k >= 1; k--) {
    for(int i = 1; i <= N - k; i++) {
      for(int j = i + k; j <= N - k + 1; j++) {
        ll cur = abs((v[i+k-1] - v[i-1]) - (v[j+k-1] - v[j-1]));
        if(cur < minVal) {
          minVal = cur;
          minK = k;
        }
      }
    }
  }

  cout << minK << '\n';
  cout << minVal;
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
