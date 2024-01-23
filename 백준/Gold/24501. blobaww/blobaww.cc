#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
int N, M;
char board[3005][3005];
int Esum[3005][3005] = {};
int Msum[3005][3005] = {};
int cnt[3005][3005] = {};

void input() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string temp;
    cin >> temp;
    for (int j = 1; j <= M; j++) {
      board[i][j] = temp[j - 1];
      if (board[i][j] == 'E')
        Esum[i][j] = 1;
      if (board[i][j] == 'M')
        Msum[i][j] = 1;
    }
  }
}

void solve() {
  // E에 대한 누적합 테이블 만들기
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      Esum[i][j] += Esum[i - 1][j] + Esum[i][j - 1] - Esum[i - 1][j - 1];
    }
  }
  // M에 대한 누적합 테이블 만들기
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      Msum[i][j] += Msum[i - 1][j] + Msum[i][j - 1] - Msum[i - 1][j - 1];
    }
  }

  // S에 대해서 E와 M의 개수를 세서 곱하기
  ll result = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (board[i][j] == 'S') {
        ll E_count = Esum[i][j]; // S의 위치 이전까지 E의 개수
        ll M_count = Msum[N][M] - Msum[i - 1][M] - Msum[N][j - 1] +
                     Msum[i - 1][j - 1]; // S의 위치 이후 M의 개수
        result = (result + (E_count * M_count) % MOD) % MOD;
      }
    }
  }
  cout << result;
}

int main(void) {
 //  (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}