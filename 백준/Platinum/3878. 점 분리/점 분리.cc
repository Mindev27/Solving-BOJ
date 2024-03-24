#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct Point{
  ll x, y, p, q;
  bool operator<(Point o) {
      if (q * o.p != p * o.q) return q * o.p < p * o.q;
      if (y != o.y) return y < o.y;
      return x < o.x;
  }
  bool operator>(Point o) { return make_pair(x, y) > make_pair(o.x, o.y); }
  bool operator<=(Point o) { return make_pair(x, y) <= make_pair(o.x, o.y); }
  bool operator==(Point o) { return x == o.x && y == o.y; }
};

ll N, M;
vector<Point> B, W, convexB, convexW;


void init() {
  B.clear();
  W.clear();
  convexB.clear();
  convexW.clear();
}

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    B.push_back({a, b});
  }
  for(int i = 0; i < M; i++) {
    ll a, b; cin >> a >> b;
    W.push_back({a, b});
  }
}

// 양수면 CCW
ll ccw(Point &a, Point &b, Point &c) {
    ll val = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
    return (val > 0) - (val < 0);
}

bool isIn(Point &a, vector<Point> &v) {
  ll temp = ccw(v[0], v[1], a);
  for(int i = 1; i < v.size(); i++) {
    if(temp * ccw(v[i], v[(i + 1) % (int)v.size()], a) <= 0) {
      return false;
    }
  }
  return true;
}

bool check(Point a, Point b, Point c, Point d) {
    ll abc = ccw(a, b, c), abd = ccw(a, b, d);
    ll cda = ccw(c, d, a), cdb = ccw(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}

vector<Point> getConvexHull(vector<Point> &v) {
  vector<Point> ret;
  sort(v.begin(), v.end());

  for(int i = 1; i < (int)v.size(); i++) {
    v[i].p = v[i].x - v[0].x;
    v[i].q = v[i].y - v[0].y;
  }

  sort(v.begin() + 1, v.end());

  for(int i = 0 ; i < (int)v.size(); i++) {
    while(ret.size() >= 2 && ccw(ret[ret.size() - 2], ret[ret.size() - 1], v[i]) <= 0) ret.pop_back();
    ret.push_back(v[i]);
  }

  return ret;
}

void solve() {
  convexB = getConvexHull(B);
  convexW = getConvexHull(W);

  bool ans = true;
  if(convexB.size() > 2) {
    for(auto &p : convexW) {
      if(isIn(p, convexB)) {
        ans = false;
        break;
      }
    }
  }

  if(convexW.size() > 2) {
    for(auto &p : convexB) {
      if(isIn(p, convexW)) {
        ans = false;
        break;
      }
    }
  }

  for(int i = 0; i < convexB.size(); i++) {
    for(int j = 0; j < convexW.size(); j++) {
      if(check(convexB[i], convexB[(i + 1) % (int)convexB.size()],
               convexW[j], convexW[(j + 1) % (int)convexW.size()]))
        { ans = false; break; }
    }
  }

  if(ans) cout << "YES\n";
  else cout << "NO\n";
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    init();
    input();
    solve();
  }

  return 0;
}