#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct Point {
  ll x, y;
};

int caseNum = 1;
ll N;
vector<Point> p;

void input() {
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    p.push_back({a, b});
  }
}

// 거리를 구하는 함수
ll dist(Point &a, Point &b) {
  return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}

void solve() {
  double result = 99999999;
  for (int i = 0; i < p.size(); i++) { for(int j = 0; j < p.size(); j++) {
    if(i == j) continue;
    double maxDist = 0;
    double minDist = 0;
    Point cur = p[i];
    Point next = p[j];
    for(int k = 0; k < p.size(); k++) {
      if(k == i || k == j) continue;
      double p1 = (cur.y - p[k].y)*(next.x - cur.x) - (cur.x - p[k].x)*(next.y - cur.y);
      double p2 = sqrt((next.x - cur.x)*(next.x - cur.x) + (next.y - cur.y)*(next.y - cur.y));
      double dist = p1 / p2;
      maxDist = max(maxDist, dist);
      minDist = min(minDist, dist);
    }
    result = min(result, maxDist - minDist);
  }}

  cout << "Case " << caseNum++ << ": ";
  cout<<fixed;
  cout.precision(2);
  cout << (ceil(result * 100) / 100.0) << "\n";
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true) {
    p.clear();
    cin >> N;
    if(N == 0) break;
    input();
    solve();
  }

  return 0;
}