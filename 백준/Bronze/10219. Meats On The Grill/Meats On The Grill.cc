#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
char a[15][15];

void solve() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = M - 1; j >= 0; j--) {
      cout << a[i][j];
    }
    cout << '\n';
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    solve();
  }
  

  return 0;
}
