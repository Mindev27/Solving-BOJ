#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int N, M;
int a[1005][1005];

void solve() {
  memset(a, 0, sizeof(a));

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int x, y; cin >> x >> y;
    a[x][y] = 1;
  }

  ll ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      // i, j를 확인
      int cnt = 0;
      for(int k = 1; k <= N; k++) {
        if(a[i][k] == 1 && a[j][k] == 1)
          cnt++;
      }

      ans += cnt * (cnt - 1) / 2;
    }
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
