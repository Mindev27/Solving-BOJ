#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

struct Edge {
    int to, cost;
};

int n, m, k, start, goal;
vector<Edge> graph[30005];
map<tuple<int, int, int>, bool> forbid;
set<tuple<int, int>> visited;

int findPath() {
    // 거리, 현재 노드, 이전 노드
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, start, start});

    while (!pq.empty()) {
        auto [curDist, curNode, prevNode] = pq.top();
        pq.pop();

        if (visited.count({curNode, prevNode})) continue;
        visited.insert({curNode, prevNode});

        if (curNode == goal) return curDist;

        for (const auto& edge : graph[curNode]) {
            int nextNode = edge.to;
            int nextDist = curDist + edge.cost;

            if (forbid[{prevNode, curNode, nextNode}]) continue;

            pq.push({nextDist, nextNode, curNode});
        }
    }

    return -1;
}


void solve() {
    cin >> m >> n >> k;
    cin >> start >> goal;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        forbid[{x, y, z}] = true;
    }

    int result = findPath();
    cout << result << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}