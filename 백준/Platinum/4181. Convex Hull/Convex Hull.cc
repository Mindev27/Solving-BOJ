#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct Point{
  ll x, y;
};

ll N;
vector<Point> p;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    ll a, b; string c;
    cin >> a >> b >> c;
    if(c == "Y") p.push_back({a, b});
  }
}

// 양수면 CCW
ll ccw(Point &a, Point &b, Point &c) {
    ll val = 1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (b.y - a.y) * (c.x - a.x);
    return (val < 0 ? -1 : (val > 0 ? 1 : 0));
}

 
void solve() {
  sort(p.begin(), p.end(), [](Point &a, Point &b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  });
  
  vector<Point> up, down;
  for(auto &cur : p){
    while(up.size() >= 2 && ccw(up[up.size()-2], up.back(), cur) > 0)
      up.pop_back();
    up.push_back(cur);
    while(down.size() >= 2 && ccw(down[down.size()-2], down.back(), cur) < 0)
      down.pop_back();
    down.push_back(cur);
  }
  down.insert(down.end(), up.rbegin() + 1, up.rend() - 1);

  cout << down.size() << '\n';
  for(Point &i : down)
    cout << i.x << ' ' << i.y << '\n';
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