#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
ll row[50000005];
ll col[50000005];

void input() {
  cin >> N >> M;
  int p; cin >> p;
  while(p--) {
    char a; int b;
    cin >> a >> b;
    if(a == 'R') row[b - 1] += 1;
    else col[b - 1] += 1;
  }
}

void solve() {
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if((row[i] + col[j]) % 2 == 1)
        ans++;
    }
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
