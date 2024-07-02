#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
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
string s;
vector<int> a, b;

void input() {
  cin >> s;
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
  a.resize((int)s.size(), 0);
  b.resize((int)s.size(), 0);

  for (int i = 0; i < s.size(); i++) {
    if(s[i] == 'B') a[i] = 1;
  }
  reverse(a.begin(), a.end());
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'A') b[i] = 1;
  }

  vector<int> result = multiply(a, b);

  for(int i = 0; i < s.size() - 1; i++) {
    cout << result[s.size() + i] << '\n';
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