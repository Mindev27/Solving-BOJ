// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, M, Xid;

vector<vector<int>> g;
vector<int> dfn, low, comp;
vector<bool> inSt;
stack<int> st;
int timerCnt = 0, compCnt = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++timerCnt;
    st.push(u);
    inSt[u] = true;

    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inSt[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        while (true) {
            int v = st.top(); st.pop();
            inSt[v] = false;
            comp[v] = compCnt;
            if (v == u) break;
        }
        compCnt++;
    }
}

void solve() {
    cin >> N >> M >> Xid;
    g.resize(N + 1, {});

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    dfn.resize(N + 1, 0);
    low.resize(N + 1, 0);
    comp.resize(N + 1, -1);
    inSt.resize(N + 1, false);
    while (!st.empty()) st.pop();
    timerCnt = 0;
    compCnt = 0;

    for (int i = 1; i <= N; i++) {
        if (!dfn[i]) tarjan(i);
    }

    int C = compCnt;

    // SCC DAG
    vector<vector<int>> dag(C);
    vector<unordered_set<int>> tmp(C);
    for (int u = 1; u <= N; u++) {
        int cu = comp[u];
        for (int v : g[u]) {
            int cv = comp[v];
            if (cu != cv) tmp[cu].insert(cv);
        }
    }
    for (int i = 0; i < C; i++) {
        dag[i].assign(tmp[i].begin(), tmp[i].end());
    }

    int sx = comp[Xid];

    vector<char> vis(C, 0);
    queue<int> q;
    vis[sx] = 1;
    q.push(sx);
    int R = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : dag[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                R++;
                q.push(v);
            }
        }
    }

    ll t = (ll)C - 1 - R;
    cout << t << '\n';
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