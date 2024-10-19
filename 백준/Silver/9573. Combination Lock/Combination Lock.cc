#include <bits/stdc++.h>
using namespace std;

int N;
int key[2][3];
bool visited[105][105][105];

void solve() {
  memset(visited, false, sizeof(visited));

  cin >> N;
  for (int i = 0; i < 3; i++) cin >> key[0][i];
  for (int i = 0; i < 3; i++) cin >> key[1][i];

  if (N <= 5) {
    cout << N * N * N << '\n';
    return;
  }

  for (int x = 0; x < 2; x++) {
    for (int i = key[x][0] - 2; i <= key[x][0] + 2; i++) {
      for (int j = key[x][1] - 2; j <= key[x][1] + 2; j++) {
        for (int k = key[x][2] - 2; k <= key[x][2] + 2; k++) {
          int a, b, c;
          a = (i <= 0) ? i + N : (i > N ? i - N : i);
          b = (j <= 0) ? j + N : (j > N ? j - N : j);
          c = (k <= 0) ? k + N : (k > N ? k - N : k);

          visited[a][b][c] = true;
          // cout << a << ' ' << b << ' ' << c << '\n';
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        if (visited[i][j][k]) ans++;
      }
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
