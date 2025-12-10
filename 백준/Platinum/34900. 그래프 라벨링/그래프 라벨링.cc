// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*

*/

int n, m;
vector<int> a;
vector<vector<int>> g;
vector<int> vis;

void solve() {
    cin >> n >> m;
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    g.resize(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vis.resize(n + 1, 0);
    vector<int> comp;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int node = 0, edge = 0;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            node++;
            edge += g[x].size();
            for (int y : g[x]) {
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
        if (edge / 2 != node - 1) {
            cout << "No\n";
            return;
        }
        comp.push_back(node);
    }

    vector<int> zero;
    for (int i = 1; i <= n; i++) if (a[i] == 0) zero.push_back(i);

    if (comp.size() != zero.size()) {
        cout << "No\n";
        return;
    }

    sort(comp.begin(), comp.end());
    ll s = 0;
    for (int i = 0; i < comp.size(); i++) {
        s += comp[i];
        if (s > zero[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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