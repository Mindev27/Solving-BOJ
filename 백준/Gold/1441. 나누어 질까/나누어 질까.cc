#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N, L, R, result = 0, endPoint = 0;
ll A[20] = {}, pb[20] = {}; // i개의 숫자 조합의 경우의 수

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

void input() {
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

void comb(int length, int index, int cur) {
  if(index == length) {
    ll temp = 1;
    for(int i = 0; i < length; i++) {
      temp = lcm(temp, pb[i]);
    }
    if(length & 1) result += endPoint / temp;
    else result -= endPoint / temp;
    return;
  }

  for(int i = cur; i < N; i++) {
    pb[index] = A[i];
    comb(length, index+1, i+1);
  }
}

void solve() {
  // L기준으로 계산
  endPoint = L - 1;
  for(int i = 1; i <= N; i++) {
    comb(i, 0, 0);
  }

  // R기준으로 계산
  ll ansL = result;
  result = 0, endPoint = R;
  for(int i = 1; i <= N; i++) {
    comb(i, 0, 0);
  }

  cout << result - ansL;
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
