#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N, a, b;
vector<int> v;
vector<int> adj[10005];

void solve() {
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    cin >> a >> b;

    for (int i = 1; i <= N; i++) {
        int cur = v[i];
        for (int j = i + cur; j <= N; j += cur) {
            adj[i].push_back(j);
        }
        for (int j = i - cur; j >= 1; j -= cur) {
            adj[i].push_back(j);
        }
    }

    queue<pii> q;
    static bool visited[10005];

    q.push({ a, 0 });
    visited[a] = true;

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == b) {
            cout << dist;
            return;
        }

        for (auto& nxt : adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push({ nxt, dist + 1 });
            }
        }
    }

    cout << -1;
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