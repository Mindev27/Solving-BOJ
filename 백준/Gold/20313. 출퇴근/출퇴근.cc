#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

const ll INF = 0x3f3f3f3f3f3f3f3f;
ll N, M, A, B, K;
ll dist[1005][105];
ll T[105][2005]; // T[i][j] := 마법 i번 j번째 간선
vector<pii> adj[1005]; // (nxt, idx)

void solve() {
    cin >> N >> M >> A >> B;
    for (int i = 0; i < M; i++) {
        ll u, v, T0;
        cin >> u >> v >> T0;
        adj[u].push_back({ v, i });
        adj[v].push_back({ u, i });
        T[0][i] = T0;
    }

    cin >> K;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < M; j++) {
            cin >> T[i][j];
        }
    }

    using Temp = pair<ll, pll>;
    priority_queue<Temp, vector<Temp>, greater<Temp>> pq; // (거리, 정점, 시간)

    pq.push({ 0, {A, 0} });
    memset(dist, INF, sizeof(dist));
    dist[A][0] = 0;

    while (!pq.empty()) {
        ll c = pq.top().X;
        ll cur = pq.top().Y.X;
        ll t = pq.top().Y.Y;
        pq.pop();

        // cout << c << ' ' << cur << ' ' << t << '\n';
        for (int nt = t; nt <= K; nt++) {
            for (auto [nxt, idx] : adj[cur]) {
                ll curCost = T[nt][idx];

                if (dist[nxt][nt] > curCost + c) {
                    dist[nxt][nt] = curCost + c;
                    pq.push({ dist[nxt][nt], {nxt, nt} });
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dist[B][i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}