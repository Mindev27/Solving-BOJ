#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

struct Point {
  ll x, y;
};

int N, L;
vector<Point> p;

void input() {
  cin >> N >> L;
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    p.push_back({a, b});
  }
}

// 양수면 CCW
ll ccw(Point &a, Point &b, Point &c) {
  ll val = 1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (b.y - a.y) * (c.x - a.x);
  return (val < 0 ? -1 : (val > 0 ? 1 : 0));
}

ll dist(Point &a, Point &b) {
  return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}

void solve() {
  sort(p.begin(), p.end(), [](Point &a, Point &b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  });

  vector<Point> up, down;
  for(auto &cur : p){
    while(up.size() >= 2 && ccw(up[up.size()-2], up.back(), cur) >= 0)
      up.pop_back();
    up.push_back(cur);
    while(down.size() >= 2 && ccw(down[down.size()-2], down.back(), cur) <= 0)
      down.pop_back();
    down.push_back(cur);
  }
  down.insert(down.end(), up.rbegin() + 1, up.rend() - 1);

  double result = 4ll * acos(0) * L; // 2 pi L을 미리 누적
  for(int i = 0; i < down.size() - 1; i++) {
    result += sqrt(dist(down[i], down[i + 1]));
  }
  result += sqrt(dist(down[down.size() - 1], down[0]));

  cout << floor(result + 0.5);
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