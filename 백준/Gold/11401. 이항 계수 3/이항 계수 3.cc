#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const ll MOD = 1000000007;
ll N, K;

// x의 a승
ll power(ll x, ll a) {
  if (a == 0) return 1;

  ll half = power(x, a / 2) % MOD;
  if (a % 2 == 0) return (half * half) % MOD;
  return (((half * half) % MOD) * x) % MOD;
}

void input() {
  cin >> N >> K;
}

void solve() {
  if(K == 1) { cout << N; return; }
  if(N == K || K == 0) { cout << 1; return; }
  if(N - K == 1) { cout << N; return; }

  ll x = 1, y = 1;
  for(ll i = K; i >= 1; i--)
    x = (x * i) % MOD;
  for(ll i = N; i >= N - K + 1; i--)
    y = (y * i) % MOD;

  ll result = ((y % MOD) * (power(x, MOD - 2) % MOD)) % MOD; 
  cout << result;
  
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
