#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX_N 200005

int N, M;
int ci, xi, hi;
int from_below[MAX_N], from_above[MAX_N];
ll min_y[MAX_N], max_y[MAX_N];

void solve() {
  cin >> N >> M;

  for (int i = 0; i <= N; ++i) {
    from_below[i] = INT_MIN;
    from_above[i] = INT_MAX;
  }

  for (int i = 0; i < M; ++i) {
    cin >> ci >> xi >> hi;
    if (ci == 0) {
      from_below[xi] = hi;
    } else {
      from_above[xi] = hi;
    }
  }

  min_y[0] = max_y[0] = 0;
  bool possible = true;

  for (int x = 1; x <= N; ++x) {

    min_y[x] = min_y[x - 1] - 1;
    if (from_below[x] != INT_MIN) {
      min_y[x] = max(min_y[x], (ll)from_below[x] + 1);
    }

    max_y[x] = N - x;

    if (from_above[x] != INT_MAX) {
      max_y[x] = min(max_y[x], (ll)from_above[x] - 1);
    }

    if (min_y[x] > max_y[x]) {
      possible = false;
      break;
    }
  }

  if (!possible || min_y[N] > 0 || max_y[N] < 0) {
    cout << "adios" << '\n';
  } else {
    cout << "stay" << '\n';
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