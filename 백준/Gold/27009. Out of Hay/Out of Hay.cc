#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int N, M;
int p[2005];
vector<pair<pii, int>> v;

int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}

void merge(int a, int b) {
  int x = find(a), y = find(b);
  if (x > y) p[x] = y;
  else p[y] = x;
}

void solve() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back({ {a, b}, c });
  }

  for (int i = 0; i <= N; i++) {
    p[i] = i;
  }

  sort(v.begin(), v.end(), [&](pair<pii, int> a, pair<pii, int> b) {
    return a.Y < b.Y;
    });

  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (find(v[i].X.X) == find(v[i].X.Y)) { continue; }

    merge(v[i].X.X, v[i].X.Y);
    ans = max(ans, v[i].Y);
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
