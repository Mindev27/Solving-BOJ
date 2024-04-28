#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N;
int board[100][100];

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  vector<int> path;
  int pre = 0;
  int getDown = 0;
  
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < N; j++) {
        if (!path.empty() && board[i][j] < pre)
          getDown++;
        pre = board[i][j];
        path.push_back(board[i][j]);
      }
    }
    else {
      for (int j = N - 1; j >= 0; j--) {
        if (!path.empty() && board[i][j] < pre)
          getDown++;
        pre = board[i][j];
        path.push_back(board[i][j]);
      }
    }
  }

  if(getDown < N * N / 2)
    reverse(path.begin(), path.end());

  for(int i : path) cout << i << ' ';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc;
  cin >> Tc;
  while (Tc--) {
    input();
    solve();
  }

  return 0;
}
