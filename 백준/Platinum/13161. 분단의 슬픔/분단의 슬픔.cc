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
    int N;
    cin >> N;
    vector<int> constraints(N);
    for (int& x : constraints) cin >> x;

    vector<vector<int>> w(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> w[i][j];
        }
    }

    int S = N;
    int T = N + 1;
    int V = N + 2;
    Dinic dinic(V);
    const int INF = 1e9;
    for (int i = 0; i < N; i++) {
        if (constraints[i] == 1) {
            dinic.add_edge(S, i, INF);
        }
        else if (constraints[i] == 2) {
            dinic.add_edge(i, T, INF);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (w[i][j] > 0) {
                dinic.add_edge(i, j, w[i][j]);
                dinic.add_edge(j, i, w[i][j]);
            }
        }
    }

    int flow = dinic.max_flow(S, T);

    vector<bool> visited(V, false);
    queue<int> q;
    q.push(S);
    visited[S] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& e : dinic.graph[u]) {
            if (e.cap > 0 && !visited[e.to]) {
                visited[e.to] = true;
                q.push(e.to);
            }
        }
    }

    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            A.push_back(i + 1);
        }
        else {
            B.push_back(i + 1);
        }
    }

    cout << flow << "\n";
    if (!A.empty()) {
        for (int i = 0; i < A.size(); i++) {
            if (i > 0) cout << " ";
            cout << A[i];
        }
    }
    cout << "\n";
    if (!B.empty()) {
        for (int i = 0; i < B.size(); i++) {
            if (i > 0) cout << " ";
            cout << B[i];
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
