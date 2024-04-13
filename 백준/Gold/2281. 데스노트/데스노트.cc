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

const int MAX = 1005;
int N, M;
int dp[MAX][MAX];
int name[MAX];

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> name[i];
  }
}

int solve(int index, int curLen) {
  if(index == N) return 0; // N번째

  int& ret = dp[index][curLen];
  if(ret != -1) return ret;

  // 다음줄에 추가하는 경우 생
  ret = (M - curLen + 1) * (M - curLen + 1);
  ret += solve(index + 1, name[index] + 1);

  if(curLen + name[index] <= M)
    ret = min(ret, solve(index + 1, curLen + name[index] + 1));

  return ret;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0);

  return 0;
}