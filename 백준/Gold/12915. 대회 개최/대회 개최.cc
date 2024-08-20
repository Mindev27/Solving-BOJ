#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int E, EM, M, MH, H;

void input() {
  cin >> E >> EM >> M >> MH >> H;
}

void solve() {
  int ans = min({E, M, H});
  E -= ans;
  M -= ans;
  H -= ans;

  while(true) {
    if(E > 0) E--;
    else {
      if(EM > 0) EM--;
      else break;
    }
    if(M > 0) M--;
    else {
      if(EM > 0 || MH > 0) {
        if(MH > EM) MH--;
        else EM--;
      }
      else break;
    }

    if(H > 0) H--;
    else {
      if(MH > 0) MH--;
      else break;
    }

    ans++;
  }

  cout << ans;
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
