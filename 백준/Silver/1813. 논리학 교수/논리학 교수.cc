#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl '\n'

using namespace std;

int N;
int cnt[55];

void solve() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    cnt[x]++;
  }

  for(int i = 50; i >= 0; i--) {
    if(cnt[i] == i) { cout << i; return; }
  }

  cout << -1;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
