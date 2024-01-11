#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MOD = 1'000'003;
int N, S, E, T;
int gridSz;
vector<vector<ll>> adj;

void input() {
  cin >> N >> S >> E >> T;
  gridSz = 5 * N;
  adj.resize(gridSz + 1, vector<ll>(gridSz + 1));
  
  for (int i = 1; i <= N; i++) {
    string a;
    cin >> a;
    for (int j = 1; j <= N; j++) {
      int cur = a[j - 1] - '0' - 1;
      if(cur == -1) continue;
      adj[i * 5][j * 5 - cur] = 1;
    }
  }
}

void makeGraph() {
  for (int i = 0; i < N; i++) {
    for(int j = 1; j <= 4; j++) {
      int index = i * 5 + j;
      adj[index][index + 1] = 1;
    }
  }
}

// 두 행렬을 곱하는 함수
vector<vector<ll>> multiple(vector<vector<ll>> &a, vector<vector<ll>> &b) {
  vector<vector<ll>> ans(gridSz + 1, vector<ll>(gridSz + 1));

  for (int i = 1; i <= gridSz; i++) {
    for (int j = 1; j <= gridSz; j++) {
      for (int k = 1; k <= gridSz; k++) {
        ans[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
      }
      ans[i][j] %= MOD;
    }
  }
  return ans;
}

void solve() {
  // 답을 저장할 단위 행렬
  vector<vector<ll>> answer(gridSz + 1, vector<ll>(gridSz + 1));
  for (int i = 1; i <= gridSz; i++)
    answer[i][i] = 1;

  // 인접행렬을 거듭제곱하면서 경우의 수를 계산
  while (T > 0) {
    if (T & 1) {
      answer = multiple(answer, adj);
      T -= 1;
    }
    adj = multiple(adj, adj);
    T /= 2;
  }
  
  // S에서 E까지 경우의 수 출력
  cout << answer[S * 5][E * 5];
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  makeGraph();
  solve();

  return 0;
}
