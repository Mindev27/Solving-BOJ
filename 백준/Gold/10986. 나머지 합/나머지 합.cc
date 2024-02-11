#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

ll N, M;
ll R[1005]; // 누적합의 나머지

void input() {
  cin >> N >> M;
  ll sum = 0;
  for(ll i = 0; i < N; i++) {
    ll a; cin >> a;
    sum += a;
    R[sum % M]++;
  }
}

void solve() {
  ll answer = R[0];
  for(ll i = 0; i < M; i++) {
    if(R[i] > 1)
      answer += (R[i] * (R[i] - 1)) / 2;
  }
  cout << answer;
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
