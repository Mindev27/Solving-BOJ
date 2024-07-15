#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int L, n;
vector<int> s;

void input() {
  cin >> L;
  s.resize(L);
  for (int i = 0; i < L; i++) {
    cin >> s[i];
  }
  cin >> n;
}

void solve() {
  sort(s.begin(), s.end());

  if (n < s[0]) {
    cout << (s[0] - n) * n - 1;
    return;
  }
  
  for (int i = 0; i < L - 1; i++) {
    if (s[i] == n || s[i + 1] == n) {
      cout << 0;
      return;
    }

    if (s[i] < n && n < s[i + 1]) {
      cout << (n - s[i]) * (s[i + 1] - n) - 1;
      return;
    }
  }
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
