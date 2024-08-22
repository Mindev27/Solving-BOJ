#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
bool visited[1000005];

void solve() {
  memset(visited, false, sizeof(visited));
  cin >> N;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if ((visited[x] || visited[y] || visited[z]) == false)
      ans++;
    visited[x] = true;
    visited[y] = true;
    visited[z] = true;
  }

  cout << ans;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
