#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int L, T, N;

void solve() {
  cin >> L >> T >> N;
  T %= 2 * L;

  vector<int> ans;
  
  while(N--) {
    int x; char y;
    cin >> x >> y;

    if(y == 'D') {
      int nPos = (x + T) % (2 * L);
      if (nPos > L) nPos = 2 * L - nPos;
      ans.push_back(nPos);
    }
    else {
      int nPos = (x - T) % (2 * L);
      if (nPos < 0) nPos += 2 * L;
      if (nPos > L) nPos = 2 * L - nPos;
      ans.push_back(nPos);
    }
  }

  sort(ans.begin(), ans.end());

  for(int i : ans) cout << i << ' ';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
