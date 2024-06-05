#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<pii> cards;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    int x = min(a, b);
    int y = max(a, b);
    cards.push_back({x, y});
  }
}

void solve() {
  sort(cards.begin(), cards.end(), [&](pii a, pii b){
   return a.X + a.Y < b.X + b.Y;
  });

  ll ans = 0;
  for(int i = 0; i < N/2; i++) {
    ans += cards[i].X;
  }
  for(int i = N/2; i < N; i++) {
    ans -= cards[i].Y;
  }

  cout << ans;
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
