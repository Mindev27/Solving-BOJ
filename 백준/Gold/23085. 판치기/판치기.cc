#include <algorithm>
#include <cmath>
#include <complex>
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

#define MOD 786433
#define G 1000

using namespace std;

int N, K, start = 0;
string s;
bool visited[3005] = {};

void input() {
  cin >> N >> K;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'H') start++;
  }
}

void solve() {
  memset(visited, false, sizeof(visited));
  queue<pii> q;
  q.push({start, 0});
  visited[start] = true;

  while(!q.empty()) {
    int cur = q.front().X;
    int step = q.front().Y;
    q.pop();

    if(cur == 0) { cout << step; return; }

    for(int i = 0; i <= K; i++) {
      int next = cur + 2 * i - K;
      if(i > N - cur) continue; // T개수
      if(K - i > cur) continue; // H개수
      if(next < 0 || next > s.size()) continue;
      if(visited[next]) continue;

      visited[next] = true;
      q.push({next, step + 1});
    }
  }

  cout << -1;
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
