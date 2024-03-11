#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

ll N, a;
vector<ll> v;

void solve() {
  v.clear();
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;

    if (v.empty() || v.back() < a) {
      v.push_back(a);
    } else {
      auto iterator = lower_bound(v.begin(), v.end(), a);
      *iterator = a;
    }
  }
  cout << v.size() << '\n';
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) solve();

  return 0;
}