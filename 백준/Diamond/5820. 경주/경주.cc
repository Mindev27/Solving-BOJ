#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

static const int INF = 1e9;

int N, K;
int subSz[200005];
bool visited[200005];
int minDepth[1000005];
vector<int> curT;
vector<vector<pii>> g(200005);

int get_size(int cur, int par) {
    subSz[cur] = 1;
    for (const auto& nxt : g[cur]) {
        int v = nxt.X;
        if (v == par || visited[v]) continue;
        subSz[cur] += get_size(v, cur);
    }
    return subSz[cur];
}


int get_cent(int cur, int par, int thr) {
    for (const auto& p : g[cur]) {
        int v = p.X;
        if (v == par || visited[v]) continue;
        if (subSz[v] > thr) return get_cent(v, cur, thr);
    }
    return cur;
}

int solveDist(int cur, int par, int dist, int depth) {
    if (dist > K) return INF;

    // min_depth[K - dist]가 있으면
    // 이미 다른 서브트리에 K - dist 거리의 노드가 있다
    int ret = minDepth[K - dist] + depth;

    for (const auto& p : g[cur]) {
        int v = p.X;
        int w = p.Y;
        if (v == par || visited[v]) continue;
        ret = min(ret, solveDist(v, cur, dist + w, depth + 1));
    }
    return ret;
}

void updateDist(int cur, int par, int dist, int depth) {
    if (dist > K) return;
    // 거리 dist에서의 최소 간선 수 갱신
    minDepth[dist] = min(minDepth[dist], depth);
    curT.push_back(dist);

    for (const auto& p : g[cur]) {
        int v = p.X;
        int w = p.Y;
        if (v == par || visited[v]) continue;
        updateDist(v, cur, dist + w, depth + 1);
    }
}

int dnc(int cur) {
    int sz = get_size(cur, -1);
    int ct = get_cent(cur, -1, sz / 2);
    visited[ct] = true;

    int ret = INF;

    for (const auto& distVal : curT) {
        minDepth[distVal] = INF;
    }
    curT.clear();

    minDepth[0] = 0;


    for (const auto& p : g[ct]) {
        int v = p.X;
        int w = p.Y;
        if (!visited[v]) {
            ret = min(ret, solveDist(v, ct, w, 1));
            updateDist(v, ct, w, 1);
        }
    }

    for (const auto& p : g[ct]) {
        int v = p.X;
        if (!visited[v]) {
            ret = min(ret, dnc(v));
        }
    }

    return ret;
}


void solve() {
    cin >> N >> K;

    // init
    for (int i = 0; i < N; i++) {
        g[i].clear();
        visited[i] = false;
        subSz[i] = 0;
    }
    for (int i = 0; i <= 1000005; i++) {
        minDepth[i] = INF;
    }
    curT.clear();


    for (int i = 0; i < N - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({ v, (int)w });
        g[v].push_back({ u, (int)w });
    }

    int ans = dnc(0);
    if (ans >= INF) ans = -1;
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) {
        solve();
    }
    return 0;
}
