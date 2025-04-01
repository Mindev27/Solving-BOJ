#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define pdd pair<double, double>

double x;
pdd st, ed;
vector<pdd> bunker;
vector<int> adj[1005];

// s와 e의 거리
inline double getsq(pdd s, pdd e) {
    return (s.X - e.X) * (s.X - e.X) + (s.Y - e.Y) * (s.Y - e.Y);
}

void solve() {
    double v, m;
    cin >> v >> m;
    x = v * m * 60;

    cin >> st.X >> st.Y;
    cin >> ed.X >> ed.Y;

    bunker.push_back(st);

    double tx, ty;
    while (cin >> tx >> ty) {
        bunker.push_back({ tx, ty });
    }

    bunker.push_back(ed);

    for (int i = 0; i < bunker.size(); i++) {
        for (int j = 0; j < bunker.size(); j++) {
            if (getsq(bunker[i], bunker[j]) <= x * x) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    queue<pii> q; // 인덱스, step
    bool visited[1005];
    fill(visited, visited + 1005, false);

    q.push({ 0, 0 });
    visited[0] = true;
    while (!q.empty()) {
        auto [cur, step] = q.front();
        q.pop();

        // cout << cur << ' ' << step << '\n';

        if (cur == bunker.size() - 1) {
            cout << "Yes, visiting " << step - 1 << " other holes.";
            return;
        }

        for (int& nxt : adj[cur]) {
            if (visited[nxt]) continue;

            visited[nxt] = true;
            q.push({ nxt, step + 1 });
        }
    }

    cout << "No.";
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