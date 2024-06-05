#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

struct Sqare {
  int xmin, xmax;
  int ymin, ymax;
};

Sqare s[5]; // idx분면의 사각형

void input() {
  for(int i = 1; i <= 4; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    s[i].xmin = min(a, c);
    s[i].xmax = max(a, c);
    s[i].ymin = min(b, d);
    s[i].ymax = max(b, d);
  }
}

// i분면과 j분면을 cor축에 대해 자르기
bool slice(int i, int j, char cor) {
  if(cor == 'y') {
    int minY = max(s[i].ymin, s[j].ymin);
    int maxY = min(s[i].ymax, s[j].ymax);

    if(minY > maxY) return true;

    s[i].ymin = s[j].ymin = minY;
    s[i].ymax = s[j].ymax = maxY;

    
  }
  else { // x축 같을때
    int minX = max(s[i].xmin, s[j].xmin);
    int maxX = min(s[i].xmax, s[j].xmax);

    if(minX > maxX) return true;

    s[i].xmin = s[j].xmin = minX;
    s[i].xmax = s[j].xmax = maxX;
  }

  return false;
}

void solve() {
  // 각 사각형의 범위를 전처리
  bool flag = false;
  flag |= slice(1, 2, 'y');
  flag |= slice(2, 3, 'x');
  flag |= slice(3, 4, 'y');
  flag |= slice(4, 1, 'x');
  if(flag == true) { cout << 0; return; }

  // 1,3사분면과 y = x + k의 교점을 통해 개수 누적
  ll ans = 0;
  for(int k = -100000; k <= 100000; k++) {
    int cnt1 = 0; // 1사분면과 직선의 교점개수

    // x좌표를 대입한 값
    int getMinY = s[1].xmin + k;
    int getMaxY = s[1].xmax + k;

    // 범위 계산
    int minY = max(s[1].ymin, getMinY);
    int maxY = min(s[1].ymax, getMaxY);

    cnt1 = max(0, maxY - minY + 1);

    int cnt3 = 0; // 3사분면과 직선의 교점개수

    // x좌표를 대입한 값
    getMinY = s[3].xmin + k;
    getMaxY = s[3].xmax + k;

    // 범위 계산
    minY = max(s[3].ymin, getMinY);
    maxY = min(s[3].ymax, getMaxY);

    cnt3 = max(0, maxY - minY + 1);

    ans += 1LL * cnt1 * cnt3;
  }

  cout << ans;
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
