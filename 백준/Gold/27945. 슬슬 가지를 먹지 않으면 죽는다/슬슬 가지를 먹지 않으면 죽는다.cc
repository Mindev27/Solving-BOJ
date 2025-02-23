#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, M;
int p[100005];
vector<pair<int, pii>> edges;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
  }

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x > y) p[x] = y;
    else p[y] = x;
}

void solve() {
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) p[i] = i;
    for(int i = 1; i <= M; i++) {
        int u, v, t; cin >> u >> v >> t;
        edges.push_back({t, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int ans = 1;
    for(auto &i : edges) {
        int t = i.X;
        int u = i.Y.X;
        int v = i.Y.Y;


        if(find(u) != find(v)) {
            merge(u, v);
            if(t == ans) {
                ans++;
            }
        }

    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
