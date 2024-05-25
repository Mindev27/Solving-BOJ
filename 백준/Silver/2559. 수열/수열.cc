#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, K;
int a[100005];
int prefix[100005];

void input() {
  cin >> N >> K;
  for(int i = 0 ; i < N; i++) {
    cin >> a[i];
  }
}

int sgmentSum(int l, int r) {
  if (l == 0)
    return prefix[r];
  return prefix[r] - prefix[l-1];
}

void solve() {
  int sum = 0;
  for(int i = 0; i < N; i++) {
    sum += a[i];
    prefix[i] = sum;
  }
  int ans = -999999999;
  for(int i = 0; i < N - K + 1; i++) {
    ans = max(ans, sgmentSum(i, i + K - 1));
  }
  cout << ans;
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
