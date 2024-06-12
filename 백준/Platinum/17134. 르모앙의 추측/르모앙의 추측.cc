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

typedef complex<double> cd;
const double PI = acos(-1);
vector<int> a, b;
vector<int> query;

void input() {
  int Tc; cin >> Tc;
  query.resize(Tc);
  for(int i = 0; i < Tc; i++) {
    cin >> query[i];
  }
}

// FFT 함수
void fft(vector<cd> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
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

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
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

  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = round(fa[i].real());
  }

  return result;
}

void solve() {
  a.resize(1000005);
  b.resize(1000005);
  
  // 에라토스테네스의 체
  bool prime[1000005];
  memset(prime, true, sizeof(prime));
  for (int i = 2; i <= 1000000; i++) {
    if (prime[i]) {
      for (int j = 2; i * j <= 1000000; j++) {
        prime[i * j] = false;
      }
    }
  }

  for (int i = 2; i <= 1000000; i++) {
    if (prime[i]) {
      // a는 홀수인 소수, b = 2 * 소수
      if(i % 2 == 1) a[i] = 1;
      if (i * 2 <= 1000000)
        b[2 * i] = 1;
    }
  }

  vector<int> result = multiply(a, b);

  for(int &q : query) {
    cout << result[q] << '\n';
  }
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
