#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, L, P;
vector<pii> gas;
priority_queue<int> pq;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    gas.push_back({a, b});
  }
  cin >> L >> P;
}

void solve() {
  sort(gas.begin(), gas.end());

  int cur = 0, cnt = 0, left = P;
  while(left < L) {
    while(cur < N && gas[cur].X <= left) { // 갈수있는 주유소는 pq에 넣기
      pq.push(gas[cur].Y);
      cur++;
    }
    if(pq.empty()) { cout << -1; return; }

    left += pq.top();
    pq.pop();
    cnt++;
  }

  cout << cnt;
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