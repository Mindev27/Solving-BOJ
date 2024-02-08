#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<pii> points;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    points.push_back({x, y});
  }
}

void solve() {
  ll result = 0;

  // 위와 왼쪽으로 꺾은 부분의 길이합 계산
  for(int i = 0; i < N - 1; i++) {
    int x = points[i].X, y = points[i].Y;
    int nx = points[i + 1].X, ny = points[i + 1].Y;

    if(x == nx && y < ny) // 위 방향
      result += ny - y;

    else if(y == ny && x > nx) // 왼쪽 방향
      result += x - nx;
  }

  // 길이 2배가 그림자의 길이
  cout << result * 2;
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