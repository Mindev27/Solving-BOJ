#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<ll> v;

void input() {
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
}

void solve() {
  stack<pll> s;
  ll ans = 0;

  for(int i = 0; i < N; i++) {
    int cnt = 1;
    while(!s.empty() && s.top().X <= v[i]) {
      if(s.top().X == v[i]) { // 키가 같으면 누적
        ans += s.top().Y;
        cnt = s.top().Y + 1;
        s.pop();
      }
      else {
        ans += s.top().Y;
        cnt = 1;
        s.pop();
      }
    }

    if(!s.empty()) {
      ans += 1;
    }

    s.push({v[i], cnt});
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
