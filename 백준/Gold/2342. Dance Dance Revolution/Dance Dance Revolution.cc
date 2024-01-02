#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 999'999'999;
vector<int> order;
int dp[100005][5][5] = {};
int w[5][5] = {};

void init() {
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= 4; i++){ // 발을 옮기는 비용계산
    w[i][i] = 1;
    w[0][i] = 2;
    w[i][i == 4 ? 1 : i + 1] = 3;
    w[i][i == 1 ? 4 : i - 1] = 3;
  }
  w[1][3] = w[3][1] = 4;
  w[2][4] = w[4][2] = 4;
}

void input() {
  order.push_back(0); // 1부터 시작하기 위함
  while(true){
    int a; cin >> a;
    if(a == 0) break;
    order.push_back(a);
  }
}

int solve(int step, int l, int r) {
  if(step == order.size()) return 0;
  if(l == r && l != 0) return INF;

  // 메모이제이션
  if(dp[step][l][r] != -1)
    return dp[step][l][r];

  int next = order[step + 1];

  return dp[step][l][r] = min(solve(step + 1, l, next) + w[r][next],
                                solve(step + 1, next, r) + w[l][next]);
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  init();
  input();
  cout << solve(0, 0, 0);
  
  return 0;
}
