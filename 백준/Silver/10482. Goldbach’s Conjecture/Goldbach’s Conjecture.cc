#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int Tc;
bool isPrime[32005];

void solve() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for(int i = 2; i <= 32000; i++) {
    for(int j = i * 2; j <= 32000; j += i) {
      isPrime[j] = false;
    }
  }

  cin >> Tc;
  while(Tc--) {
    int x; cin >> x;
    vector<pii> v;
    for(int i = 1; i <= x/2; i++) {
      if(isPrime[i] && isPrime[x - i]) {
        v.push_back({i, x - i});
      }
    }

    cout << x << " has " << v.size() << " representation(s)\n";
    for(int i = 0; i < v.size(); i++) {
      cout << v[i].X << "+" << v[i].Y << '\n';
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
