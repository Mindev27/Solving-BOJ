#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

const int INF = 0x3f3f3f3f;
int N;
string P;
int fail[1000005];
int dp[1000005];

void input() {
  cin >> N >> P;
}

int find(int x) {
  if(x < 0 || fail[x] == 0) return INF;
  if(dp[x] != -1) return dp[x];
  return dp[x] = min(find(fail[x] - 1), fail[x]);
}

void solve() {
  // 실패 함수
  for(int i = 1, j = 0; i < N; i++) {
    while(j > 0 && P[i] != P[j]) j = fail[j - 1];
    if(P[i] == P[j]) fail[i] = ++j;
  }

  memset(dp, -1, sizeof(dp));
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    int temp = find(i);
    if(temp == INF) continue;
    ans += i + 1 - temp;
  }

  cout << ans;
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