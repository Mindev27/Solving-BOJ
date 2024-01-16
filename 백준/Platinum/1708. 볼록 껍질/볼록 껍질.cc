#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

struct Point{
  ll x, y, p, q;
};

ll N;
vector<Point> p;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    p.push_back({a, b, a, b});
  }
}

// AB와 BC의 CCW여부
bool CCW(Point &a, Point &b, Point &c) {
  return 1ll*(b.x - a.x)*(c.y - a.y) > 1ll*(c.x - a.x)*(b.y - a.y);
}

void solve() {
  // y축이 가장 작은점부터 같다면 x축이 가장 작은점부터
  sort(p.begin(), p.end(), [](const Point &a, const Point &b) {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  });

  for(Point &i : p) {
    i.p -= p[0].x;
    i.q -= p[0].y;
  }

  // 0번을 제외하고 반시계방향으로 정렬
  sort(p.begin() + 1, p.end(), [](const Point &a, const Point &b) {
    ll dy1 = a.y - p[0].y, dx1 = a.x - p[0].x;
    ll dy2 = b.y - p[0].y, dx2 = b.x - p[0].x;
    double angle1 = atan2(dy1, dx1), angle2 = atan2(dy2, dx2);
    if (angle1 == angle2)
        return dy1*dy1 + dx1*dx1 < dy2*dy2 + dx2*dx2;
    return angle1 < angle2;
  });
  
  stack<int> s;
  s.push(0);
  s.push(1);
  int next = 2;

  while(next < N) {
    while(s.size() >= 2) {
      int p1 = s.top();
      s.pop();
      int p2 = s.top();
      
      if(CCW(p[p2], p[p1], p[next])) {
        s.push(p1);
        break;
      }
    }
    s.push(next);
    next++;
  }

  cout << s.size();
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