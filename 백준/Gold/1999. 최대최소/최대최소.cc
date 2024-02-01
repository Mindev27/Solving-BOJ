#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>
#define INF 1e9

int N, B, K;
int board[255][255];
int minBoard[255][255], maxBoard[255][255];
vector<pii> query;

void input() {
  cin >> N >> B >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    query.push_back({x - 1, y - 1});
  }
}

void preprocess() {
  // Initialize min and max boards
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      minBoard[i][j] = INF;
      maxBoard[i][j] = -INF;
    }
  }

  // Calculate min and max for each BxB block
  for (int i = 0; i <= N - B; i++) {
    for (int j = 0; j <= N - B; j++) {
      for (int k = 0; k < B; k++) {
        for (int l = 0; l < B; l++) {
          minBoard[i][j] = min(minBoard[i][j], board[i + k][j + l]);
          maxBoard[i][j] = max(maxBoard[i][j], board[i + k][j + l]);
        }
      }
    }
  }
}

void solve() {
  preprocess();

  for (const auto &q : query) {
    int x = q.first, y = q.second;
    cout << maxBoard[x][y] - minBoard[x][y] << '\n';
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
