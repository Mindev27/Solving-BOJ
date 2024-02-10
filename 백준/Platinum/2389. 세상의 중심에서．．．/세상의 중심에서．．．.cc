#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pdd pair<double, double>

using namespace std;

int N;
vector<pdd> points;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }
}

void solve() {
  double w = 0.1; // 가중치
  pdd answer = {0.0f, 0.0f};
  for(int i = 0; i < N; i++) { // 각점의 평균값
    answer.X += points[i].X / N;
    answer.Y += points[i].Y / N;
  }

  double dist = 0.0f;
  for(int i = 0; i < 999999; i++) {
    dist = 0.0f;
    pdd curMax = answer;
    for(auto &i : points) { // 가장 먼 점의 거리를 계산
      double x = i.X - answer.X;
      double y = i.Y - answer.Y;
      double d = sqrt(x * x + y * y);
      if(dist < d) {
        curMax = i;
        dist = d;
      }
    }
    answer = {answer.X + (curMax.X - answer.X) * w, answer.Y + (curMax.Y - answer.Y) * w};
    w *= 0.99999;
  }

  // 반지름 계산
  double radius = 0.0f;
  for(auto &i : points) {
    double x = i.X - answer.X;
    double y = i.Y - answer.Y;
    double d = sqrt(x * x + y * y);
    if(radius < d)
      radius = d;
  }

  cout.precision(15);
  cout << answer.X << ' ' << answer.Y << ' ' << radius;
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
