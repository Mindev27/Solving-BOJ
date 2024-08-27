#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>


void solve() {
  int l, r, k, x;
  cin >> l >> r >> k;
  switch(k) {
    case 2:  // 3,4,5 ...
      if(l > 3) cout << max(r - l + 1, 0);
      else cout << max(r - 2, 0);
      break;
 
    case 3:
      if(l > 6) cout << max(r/3 - (l-1)/3, 0);
      else cout << max(r/3 - (6-1)/3, 0);
      break;

    case 4:
      x = (l <= 10 && 10 <= r) ? 1 : 0;
      if(l > 14) cout << max(r/2 - (l-1)/2, 0) + x;
      else cout << max(r/2 - (14-1)/2, 0) + x;
      break;

    case 5:
      if(l > 15) cout << max(r/5 - (l-1)/5, 0);
      else cout << max(r/5 - (15-1)/5, 0);
      break;
    
    default:
      break;
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
