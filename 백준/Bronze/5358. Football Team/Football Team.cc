#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  string s;
  while (getline(cin, s)) {
    for (char c : s) {
      if (c == 'i') cout << 'e';
      else if (c == 'e') cout << 'i';
      else if (c == 'I') cout << 'E';
      else if (c == 'E') cout << 'I';
      else cout << c;
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
