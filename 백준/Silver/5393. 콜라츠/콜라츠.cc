#include <iostream>
#define ll long long

using namespace std;

void solve() {
  ll N; cin >> N;

  ll ans = N - (N / 2); // i / 2로 연결된 개수

  ll x = (N - 1) / 3 + 1; // 시작지점
  if (x % 2 == 0) x++;

  ll y = N;               // 끝지점
  if (y % 2 == 0) y--;

  if (x <= y) ans += (y - x) / 2 + 1;

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    solve();
  }
  

  return 0;
}
