#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int Tc, N, a[100005], p[100005];

void solve() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  bool flag = true;
  for (int i = 1; i <= N - 1; i++) {
    if (a[i] != a[i + 1]) { flag = false; break; }
  }

  if (flag) { cout << "NO\n"; return; }

  vector<int> v;
  for (int i = 1; i <= N; i++) {
    p[i] = i;
    if (a[i] == i) v.push_back(i);
  }

  if (v.size() == 1) {
    for (int i = N; i >= 1; i--) {
      if (a[i] != v[0]) { swap(p[i], p[v[0]]); break; }
    }
  }

  else {
    for (int i = 0; i < v.size(); i++) {
      p[v[i]] = v[(i + 1) % v.size()];
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= N; i++) cout << p[i] << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> Tc;
  while (Tc--) {
    solve();
  }

  return 0;
}