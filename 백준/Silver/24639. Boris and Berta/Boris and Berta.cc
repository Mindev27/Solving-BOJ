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

ll N, M, C;

void input() {
  cin >> N >> M >> C;
}

void solve() {
  int m, c;
  for(int i = 0; i <= (N + M - 1) / M; i++) {
    for(int j = (N - i * M) / C; j <= (N - i*M + C - 1) / C; j++) {
      if(i < 0 || j < 0) continue;
      int diff1 = abs(M * i + C * j - N);
      int diff2 = abs(M * m + C * c - N);
      if(diff1 < diff2) { m = i; c = j; }
    }
  }

  cout << m << ' ' << c;
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
