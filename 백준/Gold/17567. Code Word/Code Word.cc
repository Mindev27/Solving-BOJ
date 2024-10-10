#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

const int MOD = 1e9 + 7;
int r, c, l;
vector<vector<int>> adj;
vector<ll> dpPrev, dpCur;

bool isValid(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

void solve() {
  cin >> r >> c >> l;
  int n = r * c;

  auto idx = [&](int x, int y) {
    return x * c + y;
    };

  adj.resize(n);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int u = idx(i, j);
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx == 0 && dy == 0) continue;
          int ni = i + dx;
          int nj = j + dy;
          if (isValid(ni, nj)) {
            int v = idx(ni, nj);
            adj[u].push_back(v);
          }
        }
      }
    }
  }

  dpPrev.resize(n, 1);
  dpCur.resize(n, 0);
  ll total = n;

  for (int k = 2; k <= l; k++) {
    vector<ll> sumAdjDP(n, 0);
    for (int u = 0; u < n; u++) {
      for (int v : adj[u]) {
        sumAdjDP[u] = (sumAdjDP[u] + dpPrev[v]) % MOD;
      }
    }

    ll newTotal = 0;
    for (int u = 0; u < n; u++) {
      dpCur[u] = (total - sumAdjDP[u] - dpPrev[u]) % MOD;
      if (dpCur[u] < 0) dpCur[u] += MOD;
      newTotal = (newTotal + dpCur[u]) % MOD;
    }

    dpPrev.swap(dpCur);
    dpCur.assign(n, 0);
    total = newTotal;
  }

  cout << total << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
