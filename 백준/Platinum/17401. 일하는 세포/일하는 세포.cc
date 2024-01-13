#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int MOD = 1'000'000'007;
int T, N, D;
vector<vector<vector<ll>>> map; // T초일때 혈관의 인접행렬

void input() {
  cin >> T >> N >> D;
  map.resize(T + 1, vector<vector<ll>>(N + 1, vector<ll>(N + 1)));
  for(int i = 1; i <= T; i++){
    int M; cin >> M;
    for(int j = 1; j <= M; j++){
      int a, b, c;
      cin >> a >> b >> c;
      map[i][a][b] = c;
    }
  }
}

// 두 행렬을 곱하는 함수
vector<vector<ll>> multiple(vector<vector<ll>> &a, vector<vector<ll>> &b) {
  vector<vector<ll>> ans(N + 1, vector<ll>(N + 1));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        ans[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
      }
      ans[i][j] %= MOD;
    }
  }
  return ans;
}

void solve() {
  // 답을 저장할 단위 행렬
  vector<vector<ll>> answer(N + 1, vector<ll>(N + 1));
  for(int i = 1; i <= N; i++)
    answer[i][i] = 1;


  // T주기의 행렬을 저장할 단위 행렬
  vector<vector<ll>> tMatrix(N + 1, vector<ll>(N + 1));
  for(int i = 1; i <= N; i++)
    tMatrix[i][i] = 1;

  // T주기를 모두 곱해주기
  for(int i = 1; i <= T; i++){
    tMatrix = multiple(tMatrix, map[i]);
  }

  // 사이클을 분할정복으로 곱하기
  ll cycles = D / T;
  while (cycles > 0) {
    if (cycles % 2 == 1) {
      answer = multiple(answer, tMatrix);
    }
    tMatrix = multiple(tMatrix, tMatrix);
    cycles /= 2;
  }

  // 남은 시간 곱하기
  ll leftSecond = D % T;
  if (leftSecond > 0) {
    for (int i = 1; i <= leftSecond; ++i) {
      answer = multiple(answer, map[i]);
    }
  }

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
  }
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