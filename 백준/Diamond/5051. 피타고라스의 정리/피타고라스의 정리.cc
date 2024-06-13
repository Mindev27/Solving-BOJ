#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

typedef complex<long double> cd;
const double PI = acos(-1);
ll N;
vector<ll> a, b;

void input() {
  cin >> N;
}

// FFT 함수
void fft(vector<cd> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    ll bit = n >> 1;
    for (; j & bit; bit >>= 1) {
      j ^= bit;
    }
    j ^= bit;
    if (i < j) {
      swap(a[i], a[j]);
    }
  }

  for (int len = 2; len <= n; len <<= 1) {
    double angle = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(angle), sin(angle));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j];
        cd v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (invert) {
    for (cd &x : a) {
      x /= n;
    }
  }
}

vector<ll> multiply(const vector<ll> &a, const vector<ll> &b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  ll n = 1;
  while (n < a.size() + b.size()) {
    n <<= 1;
  }
  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) {
    fa[i] *= fb[i];
  }
  fft(fa, true);

  vector<ll> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = round(fa[i].real());
  }

  return result;
}

void solve() {
  // 1 ~ n-1까지 제곱을 mod n한 항들을 만듦
  a.resize(500001, 0);
  b.resize(N + 1, 0);
  vector<ll> eq(500001, 0);
  for (int i = 1; i < N; i++) {
    a[(1LL * i * i) % N] += 1;
    eq[(2LL * i * i) % N] += 1;
    b[i] = i * i % N;
  }

  vector<ll> result = multiply(a, a);

  ll ans = 0;
  for(int i = 1; i < N; i++) {
    ans += ((result[b[i]] + result[b[i] + N]) - eq[b[i]])/2 + eq[b[i]];
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
