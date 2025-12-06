// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MAXN = 500005;
const ll INF = 4e18;
ll n, q;

vector<pii> g[MAXN];

int sz[MAXN];
bool used[MAXN];

vector<pair<int, ll>> up[MAXN];
ll best[MAXN];

int getSize(int v, int p) {
    sz[v] = 1;
    for (auto &e : g[v]) {
        int to = e.X;
        if (to == p || used[to])
            continue;
        sz[v] += getSize(to, v);
    }
    return sz[v];
}

int getCent(int v, int p, int cap) {
    for (auto &e : g[v]) {
        int to = e.X;
        if (to == p || used[to])
            continue;
        if (sz[to] * 2 > cap)
            return getCent(to, v, cap);
    }
    return v;
}

void dfs(int v, int p, ll dist, int c) {
    up[v].push_back({c, dist});
    for (auto &e : g[v]) {
        int to = e.X;
        int w = e.Y;
        if (to == p || used[to])
            continue;
        dfs(to, v, dist + (ll)w, c);
    }
}

void build(int v) {
    int tot = getSize(v, -1);
    int c = getCent(v, -1, tot);

    used[c] = true;
    dfs(c, -1, 0, c);

    for (auto &e : g[c]) {
        int to = e.X;
        if (used[to])
            continue;
        build(to);
    }
}
void solve() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        g[i].clear();
        up[i].clear();
        used[i] = false;
        best[i] = INF;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        g[a].push_back({b, d});
        g[b].push_back({a, d});
    }

    build(1);

    while (q--) {
        int S, T;
        cin >> S >> T;
        vector<int> A(S), B(T);
        for (int i = 0; i < S; i++)
            cin >> A[i];
        for (int i = 0; i < T; i++)
            cin >> B[i];

        vector<int> vis;
        ll ans = INF;

        for (int v : A) {
            for (auto &p : up[v]) {
                int c = p.X;
                ll d = p.Y; // dist(v, c)
                if (best[c] > d) {
                    if (best[c] == INF)
                        vis.push_back(c);
                    best[c] = d;
                }
            }
        }

        for (int v : B) {
            for (auto &p : up[v]) {
                int c = p.X;
                ll d = p.Y; // dist(v, c)
                if (best[c] == INF)
                    continue;

                // dist(a,c) + dist(b,c)
                ans = min(ans, best[c] + d);
            }
        }

        cout << ans << '\n';

        for (int c : vis)
            best[c] = INF;
    }
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
