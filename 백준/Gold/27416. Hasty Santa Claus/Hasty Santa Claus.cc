#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

struct compare {
  bool operator()(pair<int, pii> a, pair<int, pii> b) {
    if (a.Y.X != b.Y.X) return a.Y.X > b.Y.X;
    if (a.Y.Y != b.Y.Y) return a.Y.Y > b.Y.Y;
    return a.X > b.X;
  }
};

int N, K;
priority_queue<pair<int, pii>, vector<pair<int, pii>>, compare> pq;

void input() {
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    pq.push({i, {x, y}});
  }
}

void solve() {
  int x = 1;
  int result[1005];

  while(!pq.empty() && x <= 31) {
    if(x < pq.top().Y.X) {
      x = pq.top().Y.X;
    }

    int cnt = 0;
    while(!pq.empty() && x == pq.top().Y.X && cnt < K) {
      result[pq.top().X] = x;
      cnt++;
      pq.pop();
    }

    while(!pq.empty() && x == pq.top().Y.X) {
      pair<int, pii> cur = pq.top();
      pq.pop();
      pq.push({cur.X, {cur.Y.X + 1, cur.Y.Y}});
    }

    x++;
  }

  for(int i = 0; i < N; i++) {
    cout << result[i] << '\n';
  }
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
