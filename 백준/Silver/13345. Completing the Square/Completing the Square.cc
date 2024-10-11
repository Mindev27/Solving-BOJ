#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

vector<pii> v;

int len(pii a, pii b) {
  return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

void solve() {
  for (int i = 0; i < 3; i++) {
    int a, b; cin >> a >> b;
    v.push_back({ a, b });
  }

  int d01 = len(v[0], v[1]);
  int d12 = len(v[1], v[2]);
  int d20 = len(v[2], v[0]);
  pii mid, ans;

  if (d12 == d20) {
    mid = { v[0].X + v[1].X, v[0].Y + v[1].Y };
    ans = { mid.X - v[2].X, mid.Y - v[2].Y };
  }
  else if (d01 == d20) {
    mid = { v[1].X + v[2].X, v[1].Y + v[2].Y };
    ans = { mid.X - v[0].X, mid.Y - v[0].Y };
  }
  else {
    mid = { v[2].X + v[0].X, v[2].Y + v[0].Y };
    ans = { mid.X - v[1].X, mid.Y - v[1].Y };
  }

  cout << ans.X << ' ' << ans.Y << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
