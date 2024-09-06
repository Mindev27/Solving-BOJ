#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

string s;

void solve() {
  cin >> s;
  int alpha[26];
  memset(alpha, 0, sizeof(alpha));
  for(char c : s) {
    alpha[c - 'a']++;
  }

  for(int i = 0; i < 26; i++) {
    cout << alpha[i] << ' ';
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

