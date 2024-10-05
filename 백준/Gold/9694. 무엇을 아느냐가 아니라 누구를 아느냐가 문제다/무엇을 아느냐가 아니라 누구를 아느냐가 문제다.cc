#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

const int INF = 1e9;

int t, n, m;
vector<vector<pii>> adj;
vector<int> minCost, parent;

void solve() {
  cin >> t;
  for (int testCase = 1; testCase <= t; ++testCase) {
    cin >> n >> m;
    adj.assign(m, vector<pii>());
    minCost.assign(m, INF);
    parent.assign(m, -1);

    for (int i = 0; i < n; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      adj[x].push_back({ y, z });
      adj[y].push_back({ x, z });
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    minCost[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
      int cost = pq.top().X;
      int cur = pq.top().Y;
      pq.pop();

      if (cost > minCost[cur]) continue;

      for (auto& next : adj[cur]) {
        int nextNode = next.X;
        int nextCost = cost + next.Y;

        if (nextCost < minCost[nextNode]) {
          minCost[nextNode] = nextCost;
          parent[nextNode] = cur;
          pq.push({ nextCost, nextNode });
        }
      }
    }

    if (minCost[m - 1] == INF) {
      cout << "Case #" << testCase << ": -1\n";
    }
    else {
      vector<int> path;
      for (int v = m - 1; v != -1; v = parent[v]) {
        path.push_back(v);
      }
      reverse(path.begin(), path.end());

      cout << "Case #" << testCase << ": ";
      for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << (i == path.size() - 1 ? "\n" : " ");
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}