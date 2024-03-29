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

int N, qNum;
vector<pii> query;
int dp[1005]
      [1005]; // i번째가 최근에 맡은 사건, j번째가 최근에 맡은 사건일때 최소이동
int choice[1005][1005];

inline int dist(pii a, pii b) { return abs(a.X - b.X) + abs(a.Y - b.Y); }

void input() {
  cin >> N >> qNum;
  query.resize(qNum + 1);
  for (int i = 1; i <= qNum; i++) {
    cin >> query[i].X >> query[i].Y;
  }
}

int solve(int l, int r) {
  if (l == qNum || r == qNum) return 0;

  int &ret = dp[l][r];
  if (ret != -1) return ret;

  int next = max(l, r) + 1;
  int distL = (l == 0) ? dist({1, 1}, query[next]) : dist(query[l], query[next]);
  int distR = (r == 0) ? dist({N, N}, query[next]) : dist(query[r], query[next]);

  int moveL = distL + solve(next, r);
  int moveR = distR + solve(l, next);

  if (moveL <= moveR) {
    choice[l][r] = 1; // 경찰차 1 선택
    ret = moveL;
  } else {
    choice[l][r] = 2; // 경찰차 2 선택
    ret = moveR;
  }

  return ret;
}

void trace(int l, int r) {
  if (l == qNum || r == qNum)
    return;
  int next = max(l, r) + 1;
  cout << choice[l][r] << '\n';
  if (choice[l][r] == 1)
    trace(next, r);
  else
    trace(l, next);
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  memset(dp, -1, sizeof(dp));

  cout << solve(0, 0) << '\n';
  trace(0, 0);

  return 0;
}