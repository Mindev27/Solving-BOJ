#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Line {
  ll a, b;
  ld s;

  Line(ll a, ll b): a(a), b(b), s(0) {}
};
int N;
vector<ll> a, b;
vector<Line> l;
ll dp[100005];

inline ld cross(Line f, Line g) {
   return (g.b - f.b) / (f.a - g.a);
}
void input() {
  cin >> N;
  a.resize(N);
  b.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> b[i];
  }
}

void solve() {
  for(int i = 1; i < N; i++) {
    Line gx = Line(b[i - 1], dp[i - 1]);

    while(l.size()) {
      gx.s = cross(gx, l.back());

      if(gx.s < l.back().s) l.pop_back();
      else break;
    }
    l.push_back(gx);

    ll x = a[i];
    int xVal = 0;
    int lo = 0, hi = l.size() - 1;
    while(lo <= hi) {
      int mid = (lo + hi) / 2;
      if(l[mid].s < x) { xVal = mid; lo = mid + 1; }
      else hi = mid - 1;
    }

    dp[i] = l[xVal].b + x * l[xVal].a;
  }

  cout << dp[N - 1];
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
