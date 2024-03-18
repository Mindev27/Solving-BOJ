#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int row, col;
bool block[605][605]; // i * j 석판이 있는지 여부
int dp[605][605]; // i * j직사각형을 쪼갤때 남는 조각의 개수

void input() {
  memset(dp, -1, sizeof(dp));
  cin >> row >> col;
  int num; cin >> num;
  while(num--) {
    int x, y; cin >> x >> y;
    block[x][y] = 1;
  }
}

int solve(int a, int b) {
  int& cur = dp[a][b];
  if(cur != -1) return cur;
  if(block[a][b]) { cur = 0; return cur; }

  cur = a * b;
  for(int i = 1; i <= a; i++)
    cur = min(cur, solve(i, b) + solve(a - i, b));

  for(int i = 1; i <= b; i++)
    cur = min(cur, solve(a, i) + solve(a, b - i));
  
  return cur;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  cout << solve(row, col);

  return 0;
}