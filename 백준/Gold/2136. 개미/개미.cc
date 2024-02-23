#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N, L, leftAnt = 0, rightAnt = 0;
ll leftMax = 0, rightMax = 0;
vector<pll> ant;

void input() {
  cin >> N >> L;

  for(ll i = 1; i <= N; i++) {
    ll x; cin >> x;
    ant.push_back({abs(x), i});
    if(x < 0) {
      leftAnt++;
      leftMax = max(leftMax, - x);
    }
    else {
      rightAnt++;
      rightMax = max(rightMax, L - x);
    }
  }
}

void solve() {
  sort(ant.begin(), ant.end());

  if(rightMax > leftMax) // 오른쪽이 더 늦게 떨어짐
    cout << ant[leftAnt].Y << ' ' << rightMax;
  else
    cout << ant[leftAnt-1].Y << ' ' << leftMax;
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