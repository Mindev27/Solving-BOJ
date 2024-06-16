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
int N, M;
string x, y;
vector<int> N_RP, N_SR, N_PS;
vector<int> M_RP, M_SR, M_PS;

void input() {
  cin >> N >> M;
  cin >> x >> y;
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

  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = round(fa[i].real());
  }

  return result;
}

// RP, SR, PS조합이 많은걸 찾아야함
// 따로 곱해주고 합을 계산
void solve() {
  N_RP.resize(N, 0), N_SR.resize(N, 0), N_PS.resize(N, 0);
  M_RP.resize(N, 0), M_SR.resize(N, 0), M_PS.resize(N, 0);
  
  for(int i = 0; i < x.size(); i++) {
    if(x[i] == 'R') N_RP[i] = 1;
    else if(x[i] == 'S') N_SR[i] = 1;
    else N_PS[i] = 1;
  }
  
  // y는 역순
  reverse(y.begin(), y.end());
  for(int i = 0; i < y.size(); i++) {
    if(y[i] == 'R') M_SR[i] = 1;
    else if(y[i] == 'S') M_PS[i] = 1;
    else M_RP[i] = 1;
  }

  vector<int> resRP = multiply(N_RP, M_RP);
  vector<int> resSR = multiply(N_SR, M_SR);
  vector<int> resPS = multiply(N_PS, M_PS);

  int ans = 0;
  for(int i = M - 1; i <= M + N - 1; i++) {
    int cur = resRP[i] + resSR[i] + resPS[i];
    ans = max(ans, cur);
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
