#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, a, b, qNum;
vector<int> query;
int dp[25][25][25]; // i번째 숫자를 볼때, j와 k가 열려있을때 최소 횟수

void input() {
  cin >> N;
  cin >> a >> b;
  cin >> qNum;
  query.resize(qNum + 1);
  for(int i = 1; i <= qNum; i++) {
    cin >> query[i];
  }
}

int solve(int step, int l, int r) {
  if(step == qNum + 1) {
    return 0;
  }

  int& ret = dp[step][l][r];
  if(ret != -1) return ret;

  ret = min(solve(step + 1, query[step], r) + abs(query[step] - l),
            (solve(step + 1, l, query[step]) + abs(query[step] - r)));

  return ret;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  memset(dp, -1, sizeof(dp));
  int x = min(a, b);
  int y = max(a, b);
  cout << solve(1, x, y);
  
  return 0;
}