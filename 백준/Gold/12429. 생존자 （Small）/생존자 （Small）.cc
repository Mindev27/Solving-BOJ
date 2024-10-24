#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Food {
  int end;
  int con;
};

void solve() {
  int t;
  cin >> t;
  for (int testCase = 1; testCase <= t; ++testCase) {
    int n;
    cin >> n;
    vector<Food> foods(n);
    for (int i = 0; i < n; ++i) {
      cin >> foods[i].end >> foods[i].con;
    }

    sort(foods.begin(), foods.end(), [](const Food& a, const Food& b) {
      return (a.end + a.con) < (b.end + b.con);
      });

    const int maxTime = 200004;
    vector<bool> hungry(maxTime, false);
    hungry[0] = true; // 시간 0에 배고픔

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int t = foods[i].end; t >= 0; --t) {
        if (hungry[t]) {
          int newTime = t + foods[i].con;
          if (newTime < maxTime) {
            hungry[newTime] = true;
            ans = max(ans, newTime);
          }
        }
      }
    }
    cout << "Case #" << testCase << ": " << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
