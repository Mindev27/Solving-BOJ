#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 0x3f3f3f3f;
string word;
int N;
vector<string> v;
int dp[55][55];

void input() {
  cin >> word >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
}

int check(string s1, string s2, int len) {
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (s1[i] != s2[i])
      cnt++;
  }
  return cnt;
}

void solve() {
  word = " " + word;

  memset(dp, INF, sizeof(dp));
  dp[0][0] = 0;

  for (int i = 1; i < word.size(); i++) {
    if (dp[i - 1][0] == INF) {
      continue;
    }
    for (string w : v) {
      int len = w.length();
      if (i + len > word.size()) {
        continue;
      }
      string subStr = word.substr(i, len);
      string sortedSubStr = subStr;
      sort(sortedSubStr.begin(), sortedSubStr.end());
      string sortedWord = w;
      sort(sortedWord.begin(), sortedWord.end());
      if (sortedSubStr == sortedWord) {
        dp[i][i + len - 1] =
            min(dp[i][i + len - 1], dp[i - 1][0] + check(subStr, w, len));
        dp[i + len - 1][0] = min(dp[i + len - 1][0], dp[i][i + len - 1]);
      }
    }
  }

  if (dp[word.size() - 1][0] != INF) {
    cout << dp[word.size() - 1][0] << endl;
  } else {
    cout << -1 << endl;
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
