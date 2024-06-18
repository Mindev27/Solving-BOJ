#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int sqrtN;

struct Query {
  int idx, s, e;
  bool operator<(Query &x) {
    if (s / sqrtN != x.s / sqrtN)
      return s / sqrtN < x.s / sqrtN;
    return e < x.e;
  }
};

vector<Query> query;
vector<int> v;
int n, q;
ll res = 0;
ll ans[100005];
ll cnt[100005];
ll table[100005];

void input() {
  cin >> n;
  sqrtN = sqrt(n);
  v.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int s, e;
    cin >> s >> e;
    query.push_back({i, s, e});
  }
}

void Plus(int a) {
  if(cnt[a] != 0)
    table[cnt[a]] -= 1;
  cnt[a] += 1;
  table[cnt[a]] += 1;
  res = max(res, cnt[a]);
}

void Minus(int a) {
  table[cnt[a]] -= 1;
  if(cnt[a] == res && table[cnt[a]] == 0)
    res -= 1;
  cnt[a] -= 1;
  table[cnt[a]] += 1;
}

void solve() {
  sort(query.begin(), query.end());

  int s = 0, e = 0;
  for (int i = 0; i < q; i++) {
    while (s < query[i].s) Minus(v[s++]);
    while (s > query[i].s) Plus(v[--s]);
    while (e < query[i].e) Plus(v[++e]);
    while (e > query[i].e) Minus(v[e--]);
    ans[query[i].idx] = res;
  }

  for (int i = 0; i < q; i++)
    cout << ans[i] << "\n";
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
