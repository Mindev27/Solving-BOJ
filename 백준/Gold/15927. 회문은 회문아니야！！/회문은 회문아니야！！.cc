#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  string s;
  cin >> s;

  // 전체가 팰린드롬인지 확인
  bool isPal = true;
  for(int i = 0; i < s.size() / 2; i++) {
    if(s[i] != s[s.size() - i - 1])
      isPal = false;
  }

  if(!isPal) {
    cout << (int)s.size();
    return;
  }

  // 다 같지 않으면 하나 땔때 팰린드롬이 아니게된다
  for(int i = 0; i < s.size() - 1; i++) {
    if(s[i] != s[i + 1]) {
      cout << s.size() - 1;
      return;
    }
  }

  // 모두 같은 문자면 불가능
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
