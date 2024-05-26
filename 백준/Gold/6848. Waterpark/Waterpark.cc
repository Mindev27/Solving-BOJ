#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<int> adj[10005];
int indegree[10005];

void input() {
  cin >> N;
  while(true) {
    int a, b; cin >> a >> b;
    if(a == 0 && b == 0) break;

    adj[a].push_back(b);
    indegree[b]++;
  }
}

void solve() {
  vector<ll> pathCount(N+1, 0);
  pathCount[1] = 1;  
  queue<int> q;

  for (int i = 1; i <= N; ++i) {
    if (indegree[i] == 0 && i != 1) {
      continue;
    }
    if (i == 1) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : adj[cur]) {
      pathCount[next] += pathCount[cur];
      indegree[next]--;

      if (indegree[next] == 0) {
        q.push(next);
      }
    }
  }

  cout << pathCount[N];
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
