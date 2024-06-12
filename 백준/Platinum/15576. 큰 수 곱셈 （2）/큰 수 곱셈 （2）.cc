#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <complex>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);
vector<int> a, b, result;

void input() {
  string A, B; cin >> A >> B;
  a.resize(A.length());
  b.resize(B.length());
  for (int i = 0; i < A.length(); i++) {
    a[i] = A[A.length() - i - 1] - '0';
  }
  for(int i = 0; i < B.length(); i++) {
    b[i] = B[B.length() - i - 1] - '0';
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

  int carry = 0;
  for (int i = 0; i < n; i++) {
    result[i] += carry;
    carry = result[i] / 10;
    result[i] %= 10;
  }

  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }

  return result;
}

string vectorToString(const vector<int> &v) {
  string result;
  for (int i = v.size() - 1; i >= 0; i--) {
    result += to_string(v[i]);
  }
  return result;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  result = multiply(a, b);
  cout << vectorToString(result);

  return 0;
}
