#include <iostream>
#include <cmath>

using namespace std;

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  int a;
  int b;
  int c;
} Line;

Point findIntersection(int a1, int b1, int c1, int a2, int b2, int c2);

int main() {
  int testCase;
  cin >> testCase;

  while (testCase--) {
    Line line[3] = {};

    for (int i = 0; i < 3; i++) {
      cin >> line[i].a >> line[i].b >> line[i].c;
    }

    // 각 직선의 기울기가 같은지 비교
    bool isCross12, isCross23, isCross31;
    isCross12 = line[0].a * line[1].b == line[0].b * line[1].a;
    isCross23 = line[1].a * line[2].b == line[1].b * line[2].a;
    isCross31 = line[2].a * line[0].b == line[2].b * line[0].a;

    // 두 직선이 평행하면 삼각형 X
    if (isCross12 || isCross23 || isCross31) {
      cout << "0.0000\n";
    } 
    else {
      // 각 교점 구하기 idx 0: 1,2번 1: 2,3번 2: 3,1번
      Point Cross[3] = {};
      Cross[0] = findIntersection(line[0].a, line[0].b, line[0].c, line[1].a, line[1].b, line[1].c);
      Cross[1] = findIntersection(line[1].a, line[1].b, line[1].c, line[2].a, line[2].b, line[2].c);
      Cross[2] = findIntersection(line[2].a, line[2].b, line[2].c, line[0].a, line[0].b, line[0].c);

      // 세 점이 모두 같다면 삼각형 X
      if (Cross[0].x == Cross[1].x && Cross[0].y == Cross[1].y) {
        cout << "0.0000\n";
      } 
      else {
        // 삼각형의 넓이 계산
        double result = Cross[0].x * Cross[1].y + Cross[1].x * Cross[2].y + Cross[2].x * Cross[0].y -
                        Cross[1].x * Cross[0].y - Cross[2].x * Cross[1].y - Cross[0].x * Cross[2].y;
        result = abs(result);
        result /= 2;
        cout << fixed;
        cout.precision(4);
        cout << result << "\n";
      }
    }
  }
}

Point findIntersection(int a1, int b1, int c1, int a2, int b2, int c2) {
    Point ret;

    double determinant = a2 * b1 - a1 * b2;
    ret.x = (c1 * b2 - c2 * b1) / determinant;
    ret.y = (a1 * c2 - a2 * c1) / determinant;

    return ret;
}