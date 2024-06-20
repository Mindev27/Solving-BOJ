#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int a, b, c, d;

void input() {
  cin >> a >> b >> c >> d;
}

void solve() {
  bool x[8];
  memset(x, false, sizeof(x));
  x[a] = 1; x[b] = 1;
  x[c] = 1, x[d] = 1;

  bool flag = false;
  if(x[0] && x[1] && x[2] && x[3]) flag = true;
  if(x[4] && x[5] && x[6] && x[7]) flag = true;

  if(x[0] && x[4] && x[5] && x[1]) flag = true;
  if(x[2] && x[3] && x[6] && x[7]) flag = true;

  if(x[0] && x[4] && x[6] && x[2]) flag = true;
  if(x[1] && x[3] && x[5] && x[7]) flag = true;

  if(flag) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    input();
    solve();
  }
  

  return 0;
}
