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

typedef complex<ld> cd;
const ll MOD = 1e9 + 7;
const double PI = acos(-1);
int N, R;
vector<ll> adj[300005];
bool visited[300005];
vector<ll> a;
vector<pii> query;

void input() {
  cin >> N >> R;
  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    query.push_back({l, r});
  }
}

// FFT 함수
void fft(vector<cd> &a, bool invert) {
  ll n = a.size();
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

  for (ll len = 2; len <= n; len <<= 1) {
    ld angle = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(angle), sin(angle));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (ll j = 0; j < len / 2; j++) {
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
    result[i] = (ll)round(fa[i].real()) % MOD;
  }

  return result;
}

// 각 리프노드까지의 거리를 계산해서 a에 표시
void labeling(int root, int depth) {
  visited[root] = true;

  bool isLeaf = true;
  for (int child : adj[root]) {
    if (!visited[child]) {
      isLeaf = false;
      labeling(child, depth + 1);
    }
  }

  if (isLeaf) {
    a[depth] += 1;
  }
}

void solve() {
  a.resize(N + 1, 0);

  memset(visited, false, sizeof(visited));
  labeling(R, 0);


  vector<ll> result = multiply(a, a);

  for (int i = 1; i < result.size(); i++) {
    result[i] = (result[i - 1] + result[i]) % MOD;
  }

  for (pii q : query) {
    ll answer = (result[q.Y] - (q.X > 0 ? result[q.X - 1] : 0) + MOD) % MOD;
    cout << answer << '\n';
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
