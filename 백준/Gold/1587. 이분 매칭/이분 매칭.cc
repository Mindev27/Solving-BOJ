#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>


void solve() {
  int nA, nB, M;
  cin >> nA >> nB;

  if(nA % 2 == 0 || nB % 2 == 0) {
    cout << nA / 2 + nB / 2;
    return;
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    if(a % 2 == 1 && b % 2 == 1) {
      cout << nA / 2 + nB / 2 + 1;
      return;
    }
  }

  cout << nA / 2 + nB / 2;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
