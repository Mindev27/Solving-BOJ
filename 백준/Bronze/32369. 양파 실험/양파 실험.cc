#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, A, B;

void solve() {
  cin >> N >> A >> B;
  int good = 1, bad = 1;
  while (N--) {
    good += A;
    bad += B;

    if (bad > good) {
      swap(good, bad);
    }
    else if (bad == good) {
      bad--;
    }
  }

  cout << good << ' ' << bad;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
