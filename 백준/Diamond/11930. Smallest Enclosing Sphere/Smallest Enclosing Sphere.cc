#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pdd pair<double, double>

int N;
struct Point {
  double x, y, z;
  Point(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}
};
vector<Point> points;

void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    double x, y, z;
    cin >> x >> y >> z;
    points.push_back(Point(x, y, z));
  }

  double w = 0.1;
  Point answer;
  for (int i = 0; i < N; i++) {
    answer.x += points[i].x / N;
    answer.y += points[i].y / N;
    answer.z += points[i].z / N;
  }

  double dist = 0.0;
  for (int iter = 0; iter < 30000; iter++) {
    dist = 0.0;
    Point curMax = answer;
    for (auto& p : points) {
      double dx = p.x - answer.x;
      double dy = p.y - answer.y;
      double dz = p.z - answer.z;
      double d = sqrt(dx * dx + dy * dy + dz * dz);
      if (dist < d) {
        curMax = p;
        dist = d;
      }
    }
    answer.x += (curMax.x - answer.x) * w;
    answer.y += (curMax.y - answer.y) * w;
    answer.z += (curMax.z - answer.z) * w;
    w *= 0.999;
  }

  double radius = 0.0;
  for (auto& p : points) {
    double dx = p.x - answer.x;
    double dy = p.y - answer.y;
    double dz = p.z - answer.z;
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    if (radius < d)
      radius = d;
  }

  cout << fixed << setprecision(2) << radius << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
