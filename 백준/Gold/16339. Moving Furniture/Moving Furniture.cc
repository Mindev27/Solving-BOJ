#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int N;
set<pii> points;
ll result = 0;

// 사각형 한변의 길이
ll sqareDist(pii a, pii b) {
  return (1LL * (a.X - b.X) * (a.X - b.X) + 1LL * (a.Y - b.Y) * (a.Y - b.Y));
}

// set에 저장
void input() {
  cin >> N;
  for (int i = 0; i < 4 * N; ++i) {
    int x, y;
    cin >> x >> y;
    points.insert({x, y});
  }
}

void solve() {
  for (int i = 0; i < N; ++i) {
    pii p1 = *points.begin();
    vector<pii> maxSqare;
    ll minDist = LLONG_MAX; // 최소거리 계산

    // p1에 대해서 대각선에 있는 점 p2 찾기
    for (auto &p2 : points) {
      if (p2 == p1) continue;

      ll dist = sqareDist(p1, p2);
      if (dist >= minDist) continue;

      // 한변길이의 dx, dy
      int dx = p2.X - p1.X;
      int dy = p2.Y - p1.Y;

      // 선분 기준 왼쪽으로 그릴 때
      pii p3 = {p1.X + dy, p1.Y - dx};
      pii p4 = {p2.X + dy, p2.Y - dx};

      // 있는지 확인
      if (points.count(p3) && points.count(p4)) {
        minDist = dist;
        maxSqare = {p1, p2, p3, p4};
      }

      // 선분 기준 오른쪽으로 그릴 때
      p3 = {p1.X - dy, p1.Y + dx};
      p4 = {p2.X - dy, p2.Y + dx};

      // 있는지 확인
      if (points.count(p3) && points.count(p4)) {
        minDist = dist;
        maxSqare = {p1, p2, p3, p4};
      }
    }

    result += minDist;

    // set에서 삭제
    for (auto &p : maxSqare) 
      points.erase(p);
  }

  cout << result << '\n';
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
