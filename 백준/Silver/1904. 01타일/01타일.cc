#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MOD = 15746;
int N;
int a[1000005];

void input() {
  cin >> N;
}

void solve() {
  memset(a, -1, sizeof(a));
  a[0] = a[1] = 1;
  a[2] = 2;

  for(int i = 3; i <= N; i++) {
    a[i] = a[i - 1] + a[i - 2];
    a[i] %= MOD;
  }

  cout << a[N];
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}