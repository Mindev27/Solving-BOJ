#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pdd pair<ld, ld>

using namespace std;

int N;
vector<pair<pdd, char>> points;

ld dist(pdd a, pdd b) {
  return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

// 두 점으로 만든 원
pair<pdd, ld> TwoPointCircle(pdd p1, pdd p2) {
  pdd center = {(p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2};
  return {center, dist(p1, center)};
}

// 세 점의 외심을 구하는 함수
pdd circumcenter(pdd p1, pdd p2, pdd p3) {
  // 예외처리
  ld temp = (p1.X - p3.X) * (p2.Y - p3.Y) - (p2.X - p3.X) * (p1.Y - p3.Y);
  if(fabs(temp) < 1e-9)
    return{numeric_limits<ld>::max(), numeric_limits<ld>::max()};
  ld dA = p1.X * p1.X + p1.Y * p1.Y;
  ld dB = p2.X * p2.X + p2.Y * p2.Y;
  ld dC = p3.X * p3.X + p3.Y * p3.Y;

  ld aux1 = (dA*(p3.Y - p2.Y) + dB*(p1.Y - p3.Y) + dC*(p2.Y - p1.Y));
  ld aux2 = -(dA*(p3.X - p2.X) + dB*(p1.X - p3.X) + dC*(p2.X - p1.X));
  ld div = (2 * (p1.X*(p3.Y - p2.Y) + p2.X*(p1.Y - p3.Y) + p3.X*(p2.Y - p1.Y)));

  ld centerX = aux1 / div;
  ld centerY = aux2 / div;

  return {centerX, centerY};
}

// 세 점으로 만든 원
pair<pdd, ld> ThreePointCircle(pdd p1, pdd p2, pdd p3) {
  pdd center = circumcenter(p1, p2, p3);
  if(center.X == numeric_limits<ld>::max() && center.Y == numeric_limits<ld>::max()) // 예외 처리
    return {{0, 0}, -1};
  
  ld radius = dist(p1, center);
  return {center, radius};
}


// 최소 외접원이 하나일때 조건을 만족하면 true
bool check(pair<pdd, ld> circle) {
  for(auto &tree : points) {
    // 감염되지 않은 나무들이 외부인지 확인
    if(tree.Y == 'N'){
      ld curDist = dist(tree.X, circle.X);
      if(circle.Y > curDist)
        return false;
    }
    // 감염된 나무들이 내부인지 확인
    if(tree.Y == 'I'){
      ld curDist = dist(tree.X, circle.X);
      if(circle.Y < curDist)
        return false;
    }
  }

  return true;
}

// 입력
void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    ld x, y;
    char z;
    cin >> x >> y >> z;
    points.push_back({{x, y}, z});
  }
} 

// 모든 경우에 대해서 false여야 다중발병이 보장되므로 Yes
void solve() {
  if(N <= 2){
    cout << "No";
    return;
  }
  // 2점으로 원을 만들때 되는지 확인
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      pair<pdd, ld> circle = TwoPointCircle(points[i].X ,points[j].X);
      if(check(circle) == true) {
        cout << "No"; return;
      }
    }
  }

  // 3점으로 원을 만들때 되는지 확인
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      for(int k = j + 1; k < N; k++) {
        pair<pdd, ld> circle = ThreePointCircle(points[i].X ,points[j].X, points[k].X);
        if(circle.Y == -1) continue;
        if(check(circle) == true) {
          cout << "No"; return;
        }
      }
    }
  }
  
  cout << "Yes";
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
