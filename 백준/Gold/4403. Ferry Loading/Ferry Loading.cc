#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

// 전역 변수 선언
int F;
vector<int> A;
vector<vector<int>> dp;
stack<bool> s;

void input() {
  cin >> F;
  F *= 100;
  int x;
  while (cin >> x &&  x) {
    A.push_back(x);
  }
  A.resize(min<int>(A.size(), 300));
}

void solve() {
  int n = A.size();
  dp.resize(n + 1, vector<int>(2 * F + 1, -1));
  dp[0][F] = F;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    bool flag = false;
    for (int j = 0; j < dp[i].size(); ++j) {
      if (dp[i][j] == -1) continue;
      int x = (sum - j + F) / 2;
      int y = (sum + j - F) / 2;
      if (x + A[i] <= F) {
        dp[i + 1][j - A[i]] = j;
        flag = true;
      }
      if (y + A[i] <= F) {
        dp[i + 1][j + A[i]] = j;
        flag = true;
      }
    }
    if (!flag) {
      dp.resize(i + 1);
      break;
    }
    sum += A[i];
  }

  int p = 0;
  while (dp.back()[p] == -1) {
    ++p;
  }

  for (int i = dp.size() - 1; i > 0; i--) {
    s.push(dp[i][p] > p);
    p = dp[i][p];
  }

  cout << s.size() << "\n";
  while (!s.empty()) {
    if(s.top()) cout << "port\n";
    else cout << "starboard\n";
    s.pop();
  }
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
