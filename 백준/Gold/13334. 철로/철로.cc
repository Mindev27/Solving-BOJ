#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N, D;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    v.push_back({a, b});
  }
  cin >> D;
}

void solve() {
  int result = 0;
  sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
    if (a.Y == b.Y) return a.X < b.X;
    return a.Y < b.Y;
  });

  
  for (int i = 0; i < N; i++) {
    if (v[i].Y > v[i].X + D) continue;
    pq.push(v[i].X);
    
    while (!pq.empty() && pq.top() < v[i].Y - D)
      pq.pop();
    result = max(result, (int)pq.size());
  }

  cout << result;
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
