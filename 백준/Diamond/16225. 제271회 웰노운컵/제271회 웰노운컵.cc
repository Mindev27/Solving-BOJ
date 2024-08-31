#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
vector<pii> v;
priority_queue<int> pq;

void solve() {
  cin >> N;
  int a[200005];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < N; i++) {
    int b; cin >> b;
    v.push_back({a[i], b});
  }

  sort(v.begin(), v.end(), [&](pii a, pii b) {
    return a.Y < b.Y;
  });

  // 0번째는 무조건 가져가야함
  ll ans = v[0].X;

  for(int i = 1; i < N - 1; i+= 2) {
    pq.push(v[i].X);
    pq.push(v[i + 1].X);

    ans += pq.top();
    pq.pop();
  }
  cout << ans << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
