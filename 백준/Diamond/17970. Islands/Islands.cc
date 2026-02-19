// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*

*/


void solve() {
    int N; cin >> N;
    vector<int> a(N), b(N);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;

    vector<int> nxtA(N + 1), prvA(N + 1), nxtB(N + 1), prvB(N + 1);
    for (int i = 0; i < N; i++) {
        int u = a[i], v = a[(i + 1) % N];
        nxtA[u] = v; prvA[v] = u;
    }
    for (int i = 0; i < N; i++) {
        int u = b[i], v = b[(i + 1) % N];
        nxtB[u] = v; prvB[v] = u;
    }

    vector<char> bad(N + 1, 0);

    vector<int> ans;

    for (int s = 1; s <= N; s++) {
        if (bad[s]) continue;

        vector<int> path;
        struct Rec { int x, ap, an, bp, bn; };
        vector<Rec> recs;

        auto eraseNode = [&](int x) {
            int ap = prvA[x], an = nxtA[x];
            int bp = prvB[x], bn = nxtB[x];
            recs.push_back({x, ap, an, bp, bn});
            nxtA[ap] = an; prvA[an] = ap;
            nxtB[bp] = bn; prvB[bn] = bp;
        };

        auto undoAll = [&]() {
            for (int i = recs.size() - 1; i >= 0; i--) {
                auto [x, ap, an, bp, bn] = recs[i];
                nxtA[ap] = x; prvA[an] = x;
                nxtA[x] = an; prvA[x] = ap;
                nxtB[bp] = x; prvB[bn] = x;
                nxtB[x] = bn; prvB[x] = bp;
            }
            recs.clear();
        };

        int cur = s;
        bool ok = false;

        while (true) {
            path.push_back(cur);
            if (path.size() == N) { ok = true; break; }

            int a1 = prvA[cur], a2 = nxtA[cur];
            int b1 = prvB[cur], b2 = nxtB[cur];

            int c1 = -1, c2 = -1;
            if (a1 == b1 || a1 == b2) c1 = a1;
            if (a2 == b1 || a2 == b2) {
                if (c1 == -1) c1 = a2;
                else if (c1 != a2) c2 = a2;
            }

            if (c1 == -1) break;

            int nxt = (c2 == -1 ? c1 : c1); // 둘 다 가능하면 아무거나
            eraseNode(cur);
            cur = nxt;
        }

        if (ok) {
            ans = path;
            break;
        }

        for (int v : path) bad[v] = 1;
        undoAll();
    }

    if (ans.empty()) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < N; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << "\n";
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
