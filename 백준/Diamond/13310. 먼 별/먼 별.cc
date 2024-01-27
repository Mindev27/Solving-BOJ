#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

struct Point {
  ll x, y, dx, dy;
};

ll N, T;
vector<Point> star;

void input() {
  cin >> N >> T;
  for (int i = 0; i < N; i++) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    star.push_back({a, b, c, d});
  }
}

// 양수면 CCW
ll ccw(Point &a, Point &b, Point &c) {
  ll val = 1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (b.y - a.y) * (c.x - a.x);
  return (val < 0 ? -1 : (val > 0 ? 1 : 0));
}

// 거리를 구하는 함수
ll dist(Point &a, Point &b) {
  return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}

ll findMaxDist(vector<Point> p, ll T) {
  // dx dy만큼 움직인 좌표로 변경
  for(int i = 0; i < p.size(); i++) {
    p[i].x += p[i].dx * T;
    p[i].y += p[i].dy * T;
  }

  // x, y순으로 오름차순 정렬
  sort(p.begin(), p.end(), [](Point &a, Point &b) {
    if (a.x == b.x)
      return a.y < b.y;
    return a.x < b.x;
  });

  // 모노톤 체인으로 컨벡스 헐 구현
  vector<Point> up, down;
  for (auto &cur : p) {
    while (up.size() >= 2 && ccw(up[up.size() - 2], up.back(), cur) >= 0)
      up.pop_back();
    up.push_back(cur);
    while (down.size() >= 2 && ccw(down[down.size() - 2], down.back(), cur) <= 0)
      down.pop_back();
    down.push_back(cur);
  }

  // 로테이팅 캘리퍼스로 거리가 최대인 두점 탐색
  ll maxDist = 0;
  ll i = 0, j = down.size() - 1;
  while (i + 1 < up.size() || j > 0) {
    maxDist = max(maxDist, dist(up[i], down[j]));

    if (i == up.size() - 1) j--;
    else if (j == 0) i++;
    else {
      Point origin = {0, 0};
      Point vecUp = {up[i + 1].x - up[i].x, up[i + 1].y - up[i].y};
      Point vecDown = {down[j].x - down[j - 1].x, down[j].y - down[j - 1].y};

      if (ccw(origin, vecUp, vecDown) < 0) i++;
      else j--;
    }
  }
  
  return maxDist;
}

void solve() {
  // 삼분탐색으로 최소인 시점 찾기
  int left = 0, right = T;
  while (right - left >= 3) {
      int mid1 = (2 * left + right) / 3;
      int mid2 = (2 * right + left) / 3;

      ll dist1 = findMaxDist(star, mid1);
      ll dist2 = findMaxDist(star, mid2);

      if (dist1 > dist2) left = mid1;
      else right = mid2;
  }

  // 구간에서 최솟값이면서 가장 빠른 시간 탐색
  ll minDist = LLONG_MAX;
  int time = left;
  for(int i = left; i <= right; i++) {
    if(minDist > findMaxDist(star, i)) {
      minDist = findMaxDist(star, i);
      time = i;
    }
  }
  cout << time << '\n' << minDist;
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