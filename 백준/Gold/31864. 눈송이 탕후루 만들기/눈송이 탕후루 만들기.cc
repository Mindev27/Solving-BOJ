#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M;
// x,y좌표기준 들어가는 눈송이 x정보 0이면 y기준 정
map<pii, vector<int>> m;
vector<pii> stick;

int GCD(int x, int y) {
  if (y == 0)
    return x;
  else
    return GCD(y, x % y);
}

void input() {
  cin >> N >> M;
  // 눈송이
  for (int i = 0; i < N; i++) {
    int a, b, gcd;
    cin >> a >> b;
    int x = abs(a), y = abs(b);

    if (a != 0 && b != 0)
      gcd = GCD(x, y);
    else
      gcd = max(x, y);

    int keyX = (gcd != 0) ? a / gcd : 0;
    int keyY = (gcd != 0) ? b / gcd : 0;

    if (a != 0) m[{keyX, keyY}].push_back(x);
    else m[{keyX, keyY}].push_back(y);
  }

  // 막대기
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    stick.push_back({a, b});
  }
}

void solve() {
  // 각 좌표당 점들을 정렬
  for (auto iter = m.begin(); iter != m.end(); iter++) {
    sort(iter->Y.begin(), iter->Y.end());
  }

  int result = 0;
  for (pii &s : stick) {
    int gcd;
    int x = abs(s.X), y = abs(s.Y);
    
    if (s.X != 0 && s.Y != 0)
      gcd = GCD(x, y);
    else
      gcd = max(x, y);

    int keyX = (gcd != 0) ? s.X / gcd : 0;
    int keyY = (gcd != 0) ? s.Y / gcd : 0;

    if (m.count({keyX, keyY})) {
      vector<int> &cur = m[{keyX, keyY}];
      int target = (s.X == 0) ? y : x;
      int cnt = upper_bound(cur.begin(), cur.end(), target) - cur.begin();
      result = max(result, cnt);
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
