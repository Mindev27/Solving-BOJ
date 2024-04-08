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

string DNA;
int dp[505][505];

void input() {
  cin >> DNA;
}

int DP(int l, int r) {
  if(r <= l) return 0;

  int& ret = dp[l][r];
  if(ret != -1) return ret;

  int cur = 0;

  // XY로 DNA구성
  for(int i = l; i < r; i++) {
    cur = max(cur, DP(l, i) + DP(i + 1, r));
  }

  // aXt, gXc로 구성
  if((DNA[l] == 'a' && DNA[r] == 't') || (DNA[l] == 'g' && DNA[r] == 'c'))
    cur = max(cur, DP(l + 1, r - 1) + 2);

  return ret = cur;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  memset(dp, -1, sizeof(dp));
  cout << DP(0, DNA.length() - 1);

  return 0;
}