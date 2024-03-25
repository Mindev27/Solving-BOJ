#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N;
vector<pll> p;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    p.push_back({x/2, y/2});
  }
}

void solve() {
  // y축이 큰 순서, 같다면 x가 큰 순서 정렬
  sort(p.begin(), p.end(), [&](pll a, pll b) {
    if(a.Y == b.Y) return a.X > b.X;
    else return a.Y > b.Y;
  });

  ll result = 0;
  ll preX = 0;
  ll preY = 0;
  for(pll &i : p) {
    if(preX >= i.X) { // 이전 x좌표와 작거나 같으면 파스
      continue;
    }

    result += (i.X - preX) * i.Y;
    preX = i.X;
    preY = i.Y;
  }

  cout << result * 4;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(  0);
  cout.tie(0);

  input();
  solve();

  return 0;
}