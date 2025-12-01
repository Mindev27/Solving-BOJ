// codforce polygon main_solution.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct Edge {
    int v;
    int phi;
    ll c;
    int cmod; // c % K
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, M, K;
    int S, T;
    if (!(cin >> N >> M >> K >> S >> T)) return 0;
 
    vector<vector<Edge>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, phi;
        long long c;
        cin >> u >> v >> c >> phi;
        g[u].push_back({v, phi, c, int(c % K)});
    }
 
    const ll INF = (1LL<<62);
    auto id = [K](int u, int r) -> int { return (u - 1) * K + r; };
 
    vector<ll> dist(1LL * N * K, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
 
    dist[id(S, 0)] = 0;
    pq.push({0, id(S, 0)});
 
    ll answer = -1;
 
    while (!pq.empty()) {
        auto [d, state] = pq.top(); pq.pop();
        if (d != dist[state]) continue;
        int u = state / K + 1;
        int r = state % K;
 
        if (u == T) { answer = d; break; }
 
        for (const auto &e : g[u]) {
            if (r % e.phi) continue;
            int r2 = r + e.cmod; if (r2 >= K) r2 -= K;
            int st2 = id(e.v, r2);
            ll nd = d + e.c;
            if (nd < dist[st2]) {
                dist[st2] = nd;
                pq.push({nd, st2});
            }
        }
    }
 
    cout << answer << '\n';
    return 0;
}