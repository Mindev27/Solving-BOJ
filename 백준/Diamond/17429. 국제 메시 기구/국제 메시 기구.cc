// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 500000;
const ll MASK = (1LL << 32) - 1;

struct Seg
{
    int n;
    ll tree[4 * MAXN + 5];
    ll mul[4 * MAXN + 5];
    ll add[4 * MAXN + 5];

    void init(int n_) {
        n = n_;
        int lim = 4 * n;
        for (int i = 1; i <= lim; i++) {
            tree[i] = 0;
            mul[i] = 1;
            add[i] = 0;
        }
    }

    void push(int node, int s, int e) {
        if (mul[node] == 1 && add[node] == 0)
            return;
        ll len = (ll)(e - s + 1);
        tree[node] = (tree[node] * mul[node] + add[node] * len) & MASK;
        if (s != e) {
            int l = node << 1, r = l | 1;
            mul[l] = (mul[l] * mul[node]) & MASK;
            add[l] = (add[l] * mul[node] + add[node]) & MASK;
            mul[r] = (mul[r] * mul[node]) & MASK;
            add[r] = (add[r] * mul[node] + add[node]) & MASK;
        }
        mul[node] = 1;
        add[node] = 0;
    }

    void _mul(int node, int s, int e, int l, int r, ll v) {
        push(node, s, e);
        if (r < s || e < l)
            return;
        if (l <= s && e <= r) {
            mul[node] = (mul[node] * v) & MASK;
            add[node] = (add[node] * v) & MASK;
            push(node, s, e);
            return;
        }
        int mid = (s + e) >> 1;
        _mul(node << 1, s, mid, l, r, v);
        _mul(node << 1 | 1, mid + 1, e, l, r, v);
        tree[node] = (tree[node << 1] + tree[node << 1 | 1]) & MASK;
    }

    void _add(int node, int s, int e, int l, int r, ll v) {
        push(node, s, e);
        if (r < s || e < l)
            return;
        if (l <= s && e <= r) {
            add[node] = (add[node] + v) & MASK;
            push(node, s, e);
            return;
        }
        int mid = (s + e) >> 1;
        _add(node << 1, s, mid, l, r, v);
        _add(node << 1 | 1, mid + 1, e, l, r, v);
        tree[node] = (tree[node << 1] + tree[node << 1 | 1]) & MASK;
    }

    ll _query(int node, int s, int e, int l, int r) {
        push(node, s, e);
        if (r < s || e < l)
            return 0;
        if (l <= s && e <= r)
            return tree[node];
        int mid = (s + e) >> 1;
        ll q1 = _query(node << 1, s, mid, l, r);
        ll q2 = _query(node << 1 | 1, mid + 1, e, l, r);
        return (q1 + q2) & MASK;
    }

    void rangeMul(int l, int r, ll v) {
        if (l > r)
            return;
        v &= MASK;
        _mul(1, 1, n, l, r, v);
    }

    void rangeAdd(int l, int r, ll v) {
        if (l > r)
            return;
        v &= MASK;
        _add(1, 1, n, l, r, v);
    }

    ll query(int l, int r) {
        if (l > r)
            return 0;
        return _query(1, 1, n, l, r);
    }
} seg;

int sz[MAXN + 5], dep[MAXN + 5], par[MAXN + 5], top[MAXN + 5], in[MAXN + 5], out[MAXN + 5];
vector<int> g[MAXN + 5], inp[MAXN + 5];
int chk[MAXN + 5];
int n, q, pv = 0;

void dfs(int v = 1) {
    chk[v] = 1;
    for (auto i : inp[v]) {
        if (chk[i])
            continue;
        chk[i] = 1;
        g[v].push_back(i);
        dfs(i);
    }
}

void dfs1(int v = 1) {
    sz[v] = 1;
    for (auto &i : g[v]) {
        dep[i] = dep[v] + 1;
        par[i] = v;
        dfs1(i);
        sz[v] += sz[i];
        if (sz[i] > sz[g[v][0]])
            swap(i, g[v][0]);
    }
}

void dfs2(int v = 1) {
    in[v] = ++pv;
    for (auto i : g[v]) {
        top[i] = (i == g[v][0] ? top[v] : i);
        dfs2(i);
    }
    out[v] = pv;
}

void pathAdd(int a, int b, ll v) {
    v &= MASK;
    while (top[a] ^ top[b]) {
        if (dep[top[a]] < dep[top[b]])
            swap(a, b);
        int st = top[a];
        seg.rangeAdd(in[st], in[a], v);
        a = par[st];
    }
    if (dep[a] > dep[b])
        swap(a, b);
    seg.rangeAdd(in[a], in[b], v);
}

void pathMul(int a, int b, ll v) {
    v &= MASK;
    while (top[a] ^ top[b]) {
        if (dep[top[a]] < dep[top[b]])
            swap(a, b);
        int st = top[a];
        seg.rangeMul(in[st], in[a], v);
        a = par[st];
    }
    if (dep[a] > dep[b])
        swap(a, b);
    seg.rangeMul(in[a], in[b], v);
}

ll pathQuery(int a, int b) {
    ll ret = 0;
    while (top[a] ^ top[b]) {
        if (dep[top[a]] < dep[top[b]])
            swap(a, b);
        int st = top[a];
        ret = (ret + seg.query(in[st], in[a])) & MASK;
        a = par[st];
    }
    if (dep[a] > dep[b])
        swap(a, b);
    ret = (ret + seg.query(in[a], in[b])) & MASK;
    return ret;
}

void solve() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        g[i].clear();
        inp[i].clear();
        chk[i] = 0;
        sz[i] = dep[i] = par[i] = top[i] = in[i] = out[i] = 0;
    }
    pv = 0;

    for (int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        inp[s].push_back(e);
        inp[e].push_back(s);
    }

    dfs();
    dfs1();
    top[1] = 1;
    dfs2();

    seg.init(n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            ll v;
            cin >> x >> v;
            seg.rangeAdd(in[x], out[x], v);
        }
        else if (op == 2) {
            int x, y;
            ll v;
            cin >> x >> y >> v;
            pathAdd(x, y, v);
        }
        else if (op == 3) {
            int x;
            ll v;
            cin >> x >> v;
            seg.rangeMul(in[x], out[x], v);
        }
        else if (op == 4) {
            int x, y;
            ll v;
            cin >> x >> y >> v;
            pathMul(x, y, v);
        }
        else if (op == 5) {
            int x;
            cin >> x;
            ll ans = seg.query(in[x], out[x]) & MASK;
            cout << ans << '\n';
        }
        else if (op == 6) {
            int x, y;
            cin >> x >> y;
            ll ans = pathQuery(x, y) & MASK;
            cout << ans << '\n';
        }
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
