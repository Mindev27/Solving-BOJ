#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
int adj[300][300];
vector<pii> range;

void input() {
  cin >> N >> M;
  memset(adj, 0, sizeof(adj));
  range.resize(N + 1, {1, N});
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    adj[a][b] = 1;
  }
}

void solve() {
  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(adj[i][k] && adj[k][j]) {
          adj[i][j] = 1;
        }
      }
    }
  }

  //불가능한 경우
  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(adj[i][j] && adj[j][i]) {
        cout << "-1";
        return;
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(adj[i][j]) range[i].Y--;
      if(adj[j][i]) range[i].X++;
    }
    cout << range[i].X << ' ' << range[i].Y << '\n';
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
