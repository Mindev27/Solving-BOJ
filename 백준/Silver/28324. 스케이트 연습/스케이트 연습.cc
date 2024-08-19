#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<int> v;

void input() {
  cin >> N;
  v.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i];
  }
}

void solve() {
  ll ans = 0, speed = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(speed + 1 <= v[i]) speed++;
    else speed = v[i];
    ans += speed;
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
