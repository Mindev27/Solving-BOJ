#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
  long long x;
  long long y;
};

long double getPolygonArea(const vector<Point>& points) {
  long double area = 0.0;
  int n = points.size();
  
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += (long double)(points[i].x * points[j].y - points[j].x * points[i].y);
  }
  
  area = abs(area) / 2.0;
  return area;
}

int main() {
  int n;
  cin >> n;
  
  vector<Point> points(n);
  
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }

  long double area = getPolygonArea(points);

  cout.precision(1);
  cout << fixed << area;

  return 0;
}
