#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct Point {
  ll x, y;
};

ll N;
vector<Point> p;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    p.push_back({a, b});
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

void solve() {
  sort(p.begin(), p.end(), [](Point &a, Point &b) {
    if (a.x == b.x)
      return a.y < b.y;
    return a.x < b.x;
  });

  vector<Point> up, down;
  for (auto &cur : p) {
    while (up.size() >= 2 && ccw(up[up.size() - 2], up.back(), cur) >= 0)
      up.pop_back();
    up.push_back(cur);
    while (down.size() >= 2 && ccw(down[down.size() - 2], down.back(), cur) <= 0)
      down.pop_back();
    down.push_back(cur);
  }

  ll maxDist = 0;
    int i = 0, j = down.size() - 1;
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

  cout<<fixed;
  cout.precision(10);
  cout << sqrt(maxDist) << "\n";
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