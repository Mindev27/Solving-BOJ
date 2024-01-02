#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct ore {
  int s; // 시작 시간
  int e; // 끝 시간
  int v; // 가치
};

int m, n;
int price[10005] = {};
int dp[15005] = {};
vector<ore> ores;

void input() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) // 가격 정보 입력
    cin >> price[i];

  for (int i = 0; i < n; i++) { // 광물의 가치를 미리 계산
    int a, b, c;
    cin >> a >> b >> c;
    ores.push_back({a, b, (b - a) * price[c]});
  }
}

bool compare(ore a, ore b) { return a.e < b.e; }

void solve() {
  sort(ores.begin(), ores.end(), compare);

  int index = 0;
  for (int i = 1; i <= 15000; i++) { // i에 끝날때 얻는 최대금액
    // 끝나는 모든 광물들에 대해 dp 업데이트
    while (index <= n && ores[index].e == i) {
      dp[i] = max(dp[i], dp[ores[index].s] + ores[index].v);
      index++;
    }
    dp[i] = max(dp[i], dp[i - 1]); // 이전값과 비교
  }

  cout << dp[15000];
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
