#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>


string word;
unordered_set<string> dict;
int N, cnt[26], result = 0;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    char x; int y;
    cin >> x >> y;
    cnt[x - 'a'] = y;
  }
  cin >> word;
}

string rev(int l, int r, string s) {
  reverse(s.begin() + l, s.begin() + r + 1);
  return s;
}

void backTracking(int l, int r, string s) {
  int mid = (l + r) / 2;
  if (l >= r) {
    if (!dict.count(s)) { dict.insert(s); result++; }
    return;
  }

  if (l <= mid) {
    string revS = rev(l, mid, s);
    backTracking(mid + 1, r, revS);
  }
  if (mid + 1 <= r) {
    string revS = rev(mid + 1, r, s);
    backTracking(l, mid, revS);
  }

  if ((r - l + 1) % 2 == 0) return;

  if (l <= mid - 1) {
    string revS = rev(l, mid - 1, s);
    backTracking(mid, r, revS);
  }
  if (mid <= r) {
    string revS = rev(mid, r, s);
    backTracking(l, mid - 1, revS);
  }
}

void solve() {
  for (int i = 0; i < word.size(); i++) {
    for (int j = 1; i + j <= word.size(); j++) {
      string cur = word.substr(i, j);
      vector<int> left(26, 0);
      for (int k = 0; k < cur.size(); k++) {
        left[cur[k] - 'a']++;
      }

      bool canGet = true;
      for (int k = 0; k < 26; k++) {
        if (left[k] != cnt[k]) {
          canGet = false;
          break;
        }
      }

      if (!canGet) continue;

      backTracking(0, j - 1, cur);
    }
  }

  cout << result;
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
