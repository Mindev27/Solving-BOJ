#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
string s;

void input() {
  cin >> N >> s;
}

void solve() {
  ll ans = 0;
  
  stack<int> st;
  for(int i = 0; i < N; i++) {
    if(s[i] == 'T') {
      if(st.empty() || (st.top() - i) % 2 == 0) {
        st.push(i);
      }
      else {
        ans += i;
        ans -= st.top();
        st.pop();
      }
    }
  }

  if(st.size()) cout << "-1\n";
  else cout << ans << '\n';
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
