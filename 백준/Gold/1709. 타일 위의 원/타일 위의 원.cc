#include <iostream>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

ll N, R;

void solve() {
  R = N / 2; // 반지름 길이
  ll rSqare = R * R;

  ll cnt = 0;
  for(ll x = 1, y = R - 1; x <= R + 1 && y >= 0;) {
    ll dist = x * x + y * y;

    if(dist < rSqare) { // 포함되는 경우
      x++; cnt++;
    }
    else if(dist == rSqare) { // 정확히 점을 지나는 경우
      x++; y--; cnt++;
    }
    else{       // 포함되지 않는 경우
      y--; cnt++;
    }
  }
  cout << 4 * cnt;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  solve();

  return 0;
}