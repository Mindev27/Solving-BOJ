#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M, K;
vector<pair<pii, int>> v;

void input() {
  cin >> N >> M;
  cin >> K;
  for(int i = 0; i < K; i++) {
    int x, y, f; cin >> x >> y >> f;
    v.push_back({{x - 1, y - 1}, f});
  }
}

inline int dist(pii a, pii b) {
  return abs(a.X - b.X) + abs(a.Y - b.Y);
}

bool canGet(pii a, pii b) {
  return a.X <= b.X && a.Y <= b.Y;
}

bool check(int x) {
  int sz = v.size();
  int dp[sz];
  memset(dp, -1, sizeof(dp));
  dp[0] = x;
  for(int i = 1; i < sz; i++) {
    for(int j = 0; j < i; j++) {
      if(!canGet(v[j].X, v[i].X)) continue;
      if(dp[j] >= dist(v[j].X, v[i].X))
        dp[i] = max(dp[i], dp[j] - dist(v[j].X, v[i].X) + v[i].Y);
    }
  }

  return dp[sz - 1] != -1;
}

void solve() {
  v.push_back({{0, 0}, 0});
  v.push_back({{N - 1, M - 1}, 0});
  sort(v.begin(), v.end(), [&](pair<pii, int> a, pair<pii, int> b) {
    return a.X.X + a.X.Y < b.X.X + b.X.Y;
  });

  int lo = 0, hi = 10000;
  while(lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) hi = mid;
    else lo = mid;
  }

  cout << hi;
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
