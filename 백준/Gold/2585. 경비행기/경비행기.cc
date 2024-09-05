#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, K;
bool visited[1005];
vector<pii> pos;

inline int dist(pii &a, pii &b) {
  return 1LL * (a.X - b.X) * (a.X - b.X) 
      + 1LL * (a.Y - b.Y) * (a.Y - b.Y);
}

bool check(ll maxD) {
  queue<pair<pii, int>> q;
  q.push({{0, 0}, 0});
  visited[0] = true;

  while(!q.empty()) {
    pii cur = q.front().X;
    int step = q.front().Y;
    q.pop();
    
    if(cur.X == 10000 && cur.Y == 10000) {
      return true;
    }

    if(step > K) continue;

    for(int i = 1; i <= N+1; i++) {
      if(visited[i]) continue;

      if(dist(pos[i], cur) <= maxD) {
        visited[i] = true;
        q.push({pos[i], step + 1});
      }
    }
  }

  return false;
}

void solve() {
  cin >> N >> K;
  pos.resize(N + 2);

  pos[0] = {0, 0};

  for (int i = 1; i <= N; i++) {
      cin >> pos[i].X >> pos[i].Y;
  }
  pos[N + 1] = {10000, 10000};

  ll lo = 1, hi = 15000;
  while(lo <= hi) {
    memset(visited, false, sizeof(visited));
    int mid = (lo + hi) / 2;
    if(check(100LL * mid * mid)) hi = mid - 1;
    else lo = mid + 1;
  }

  cout << lo;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
