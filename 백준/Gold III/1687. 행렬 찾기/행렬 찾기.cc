#include <algorithm>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
int board[350][350];
ll temp[350][350]; // i행에서 j까지 최대 연속 0길이

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      char x; cin >> x;
      board[i][j] = x - '0';
    }
  }
}

void solve() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      temp[i][j] = board[i][j] == 1 ? 0 : temp[i][j - 1] + 1;
    }
  }

  ll result = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      ll minMax = LLONG_MAX;
      for(int k = 0; k <= i; k++) { // 각 행을 검사하면서 최대넓이계산
        minMax = min(minMax, temp[i - k][j]);
        result = max(result, minMax * (k + 1));
      }
    }
  }

  cout << result;
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
