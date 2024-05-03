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

const int SIZE = 105;
const int DIV = 1000000007;
ll adj[SIZE][SIZE], answer[SIZE][SIZE];
ll N, K;

void multiple(ll a1[][SIZE], ll a2[][SIZE]) {
  ll temp[SIZE][SIZE];
  memset(temp, 0, sizeof(temp));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        temp[i][j] = (temp[i][j] + a1[i][k] * a2[k][j]) % DIV;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      a1[i][j] = temp[i][j];
    }
  }
}

void input() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> adj[i][j];
    }
  }
}

void solve() {
  // answer은 단위 행렬
  memset(answer, 0, sizeof(answer));
  for (int i = 0; i < N; i++)
    answer[i][i] = 1;

  while (K > 0) {
    if (K & 1) {
      multiple(answer, adj);
      K -= 1;
    }
    multiple(adj, adj);
    K /= 2;
  }

  ll result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      result = (result + answer[i][j]) % DIV;
    }
  }

  cout << result % DIV;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}