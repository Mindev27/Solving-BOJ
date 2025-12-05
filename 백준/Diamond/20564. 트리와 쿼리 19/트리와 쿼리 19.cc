// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int MAXN = 500000;
const int MAXSEG = 4 * MAXN + 5;

ll comb2(ll x) { return x * (x - 1) / 2; }

struct Seg {
    ll sum1[MAXSEG];
    ll sum2[MAXSEG];
    ll lazy[MAXSEG];
    int n;

    void init(int n_) {
        n = n_;
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        memset(lazy, 0, sizeof(lazy));
    }

    void push(int node, int s, int e) {
        ll d = lazy[node];
        if (!d) return;
        ll len = (ll)e - s + 1;
        sum2[node] += 2LL * d * sum1[node] + d * d * len;
        sum1[node] += d * len;
        if (s != e) {
            lazy[node << 1] += d;
            lazy[node << 1 | 1] += d;
        }
        lazy[node] = 0;
    }

    void build(int node, int s, int e, const ll *base) {
        if (s == e) {
            sum1[node] = base[s];
            sum2[node] = base[s] * base[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(node << 1, s, mid, base);
        build(node << 1 | 1, mid + 1, e, base);
        sum1[node] = sum1[node << 1] + sum1[node << 1 | 1];
        sum2[node] = sum2[node << 1] + sum2[node << 1 | 1];
    }

    void update(int node, int s, int e, int l, int r, ll v) {
        if (l > r) return;
        push(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] += v;
            push(node, s, e);
            return;
        }
        int mid = (s + e) >> 1;
        update(node << 1, s, mid, l, r, v);
        update(node << 1 | 1, mid + 1, e, l, r, v);
        sum1[node] = sum1[node << 1] + sum1[node << 1 | 1];
        sum2[node] = sum2[node << 1] + sum2[node << 1 | 1];
    }

    ll allSum1() { push(1, 1, n); return sum1[1]; }
    ll allSum2() { push(1, 1, n); return sum2[1]; }
} seg;

int n, q;
int col[MAXN + 5];
int par[MAXN + 5], dep[MAXN + 5], sz[MAXN + 5], heavy[MAXN + 5];
int top[MAXN + 5], in[MAXN + 5];
ll subW[MAXN + 5];
vector<int> g[MAXN + 5];
int pv;

void dfs() {
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        heavy[i] = 0;
    }
    for (int v = n; v >= 2; v--) {
        int p = par[v];
        sz[p] += sz[v];
        if (!heavy[p] || sz[v] > sz[heavy[p]]) heavy[p] = v;
    }

    pv = 0;
    vector<pair<int,int>> st;
    st.reserve(n);
    st.push_back({1, 1});
    while (!st.empty()) {
        auto [v, h] = st.back();
        st.pop_back();
        int cur = v;
        while (cur) {
            top[cur] = h;
            in[cur] = ++pv;
            for (int nx : g[cur]) {
                if (nx == heavy[cur]) continue;
                st.push_back({nx, nx});
            }
            cur = heavy[cur];
        }
    }
}

void addRoot(int v, int delta) {
    while (top[v] != 1) {
        seg.update(1, 1, n, in[top[v]], in[v], delta);
        v = par[top[v]];
    }
    seg.update(1, 1, n, in[1], in[v], delta);
}

ll getAns(ll K) {
    ll S1 = seg.allSum1();
    ll S2 = seg.allSum2();
    ll all = (S2 - S1) / 2;
    return all - comb2(K);
}

void solve() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> col[i];
        g[i].clear();
    }

    par[1] = 0;
    dep[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        g[par[i]].push_back(i);
        dep[i] = dep[par[i]] + 1;
    }

    for (int i = 1; i <= n; i++) subW[i] = col[i];
    for (int i = n; i >= 2; i--) subW[par[i]] += subW[i];

    dfs();

    ll base[MAXN + 5]{};
    for (int v = 1; v <= n; v++) base[in[v]] = subW[v];

    seg.init(n);
    seg.build(1, 1, n, base);

    ll K = subW[1];
    cout << getAns(K) << '\n';

    while (q--) {
        int x;
        cin >> x;
        int delta = (col[x] ? -1 : +1);
        col[x] ^= 1;
        K += delta;
        addRoot(x, delta);
        cout << getAns(K) << '\n';
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
