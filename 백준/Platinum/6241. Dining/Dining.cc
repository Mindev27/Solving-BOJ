#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

struct Edge {
    int to;
    int rev;
    int cap;
};

class Dinic {
public:
    int V;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

    Dinic(int V) : V(V), graph(V, vector<Edge>()), level(V, -1), ptr(V, 0) {}

    void add_edge(int from, int to, int cap) {
        Edge a = { to, (int)graph[to].size(), cap };
        Edge b = { from, (int)(graph[from].size()), 0 };
        graph[from].push_back(a);
        graph[to].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& e : graph[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int t, int flow) {
        if (u == t) return flow;
        for (int& i = ptr[u]; i < graph[u].size(); i++) {
            Edge& e = graph[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int pushed = dfs(e.to, t, min(flow, e.cap));
                if (pushed > 0) {
                    e.cap -= pushed;
                    graph[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, INT32_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

void solve() {
    int n, f, d;
    cin >> n >> f >> d;
    int s = 0, t = 2 * n + f + d + 1;
    Dinic dinic(t + 1);

    for (int i = 1; i <= f; i++) dinic.add_edge(s, i, 1);
    for (int i = 1; i <= d; i++) dinic.add_edge(2 * n + f + i, t, 1);

    for (int i = 1; i <= n; i++) {
        int fi, di;
        cin >> fi >> di;
        for (int j = 0; j < fi; j++) {
            int x;
            cin >> x;
            dinic.add_edge(x, f + i, 1);
        }
        dinic.add_edge(f + i, f + n + i, 1);
        for (int j = 0; j < di; j++) {
            int x;
            cin >> x;
            dinic.add_edge(f + n + i, 2 * n + f + x, 1);
        }
    }

    cout << dinic.max_flow(s, t) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    solve();

    return 0;
}
