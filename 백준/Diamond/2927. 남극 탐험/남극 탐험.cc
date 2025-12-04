// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Seg
{
    int n;
    ll tree[1 << 19];
    void init(int n_) {
        n = 1;
        while (n < n_)
            n <<= 1;
        memset(tree, 0, sizeof(tree));
    }
    void update(int x, ll v) {
        x |= n;
        tree[x] += v;
        while (x >>= 1)
            tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
    ll query(int l, int r) {
        if (l > r)
            return 0;
        l |= n;
        r |= n;
        ll ret = 0;
        while (l <= r) {
            if (l & 1)
                ret += tree[l++];
            if (!(r & 1))
                ret += tree[r--];
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }
} seg;

int p[300005];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}
bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (a > b)
        swap(a, b);
    p[b] = a;
    return true;
}

int n, q;
vector<int> g[300005];
int sz_[300005], dep[300005], par_[300005], top[300005], in_[300005],
    out_[300005];
int pv;
int curVal[300005];

void dfs1(int v, int p) {
    sz_[v] = 1;
    par_[v] = p;
    for (auto &i : g[v]) {
        if (i == p)
            continue;
        dep[i] = dep[v] + 1;
        dfs1(i, v);
        sz_[v] += sz_[i];
        if (sz_[i] > sz_[g[v][0]])
            swap(i, g[v][0]);
    }
}

void dfs2(int v, int t) {
    top[v] = t;
    in_[v] = ++pv;
    if (!g[v].empty()) {
        int h = g[v][0];
        if (h != par_[v])
            dfs2(h, t);
    }
    for (auto i : g[v]) {
        if (i == par_[v] || i == g[v][0])
            continue;
        dfs2(i, i);
    }
    out_[v] = pv;
}

ll pathQuery(int a, int b) {
    ll ret = 0;
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]])
            swap(a, b);
        int st = top[a];
        ret += seg.query(in_[st], in_[a]);
        a = par_[st];
    }
    if (dep[a] > dep[b])
        swap(a, b);
    ret += seg.query(in_[a], in_[b]);
    return ret;
}

struct Q
{
    char t;
    int a, b;
} qs[300005];
vector<pair<int, int>> edges;
int initPeng[300005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> initPeng[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (s[0] == 'b')
            qs[i] = {'b', a, b};
        else if (s[0] == 'p')
            qs[i] = {'p', a, b};
        else
            qs[i] = {'e', a, b};
    }

    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= q; i++) {
        if (qs[i].t == 'b') {
            if (uni(qs[i].a, qs[i].b)) {
                edges.push_back({qs[i].a, qs[i].b});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        g[i].clear();

    for (auto &e : edges) {
        g[e.X].push_back(e.Y);
        g[e.Y].push_back(e.X);
    }

    pv = 0;
    for (int i = 1; i <= n; i++) {
        sz_[i] = dep[i] = par_[i] = top[i] = in_[i] = out_[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (par_[i] == 0) {
            if (g[i].empty()) {
                par_[i] = -1;
                in_[i] = ++pv;
                out_[i] = pv;
                top[i] = i;
            }
            else {
                dfs1(i, -1);
                dfs2(i, i);
            }
        }
    }

    seg.init(pv);
    for (int i = 1; i <= n; i++) {
        curVal[i] = initPeng[i];
        seg.update(in_[i], curVal[i]);
    }

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 1; i <= q; i++) {
        char t = qs[i].t;
        int a = qs[i].a;
        int b = qs[i].b;
        if (t == 'b') {
            if (uni(a, b))
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else if (t == 'p') {
            int diff = b - curVal[a];
            curVal[a] = b;
            seg.update(in_[a], diff);
        }
        else {
            if (find(a) != find(b)) {
                cout << "impossible\n";
            }
            else {
                cout << pathQuery(a, b) << '\n';
            }
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
