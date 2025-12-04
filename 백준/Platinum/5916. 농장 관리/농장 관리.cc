// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

// HLD for education
// 공부용 따라치기
// https://justicehui.github.io/hard-algorithm/2020/01/24/hld/

struct Seg {
    ll tree[1 << 19];
    ll lazy[1 << 19];
    int n;

    void init(int n_) {
        n = n_;
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
    }

    void push(int node, int s, int e) {
        if (!lazy[node]) return;
        tree[node] += lazy[node] * (1LL * e - s + 1);
        if (s != e) {
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void _update(int node, int s, int e, int l, int r, ll v) {
        push(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] += v;
            push(node, s, e);
            return;
        }
        int mid = (s + e) >> 1;
        _update(node << 1, s, mid, l, r, v);
        _update(node << 1 | 1, mid + 1, e, l, r, v);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    ll _query(int node, int s, int e, int l, int r) {
        push(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) >> 1;
        return _query(node << 1, s, mid, l, r)
             + _query(node << 1 | 1, mid + 1, e, l, r);
    }

    // [l, r] 구간에 v 더하기
    void update(int l, int r, int v) {
        if (l > r) return;
        _update(1, 1, n, l, r, v);
    }

    // [l, r] 구간 합
    ll query(int l, int r) {
        if (l > r) return 0;
        return _query(1, 1, n, l, r);
    }
} seg;

int sz[100005], dep[100005], par_[100005], top[100005], in[100005], out[100005];
vector<int> g[100005];   // HLD용 그래프
vector<int> inp[100005]; // 입력용 그래프

int chk[100005];

int n, m;
int pv = 0;

// 이걸로 g만들기
void dfs(int v = 1) {
    chk[v] = 1;
    for (auto i : inp[v]) {
        if (chk[i]) continue;
        chk[i] = 1;
        g[v].push_back(i);
        dfs(i);
    }
}

// 이걸로 sz dep 계산하고 g에서 g[v][0]을 Heavy Edge로 찾아두기
void dfs1(int v = 1) {
    sz[v] = 1;
    for (auto &i : g[v]) {
        dep[i] = dep[v] + 1; 
        par_[i] = v;
        dfs1(i); 
        sz[v] += sz[i];
        // 항상 0번째가 Heavy Edge
        if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]); 
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

void pathUpdate(int a, int b) {
    while (top[a] ^ top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        seg.update(in[st], in[a], 1);
        a = par_[st];
    }
    if (dep[a] > dep[b]) swap(a, b);
    // 간선 기준이므로 LCA 자신은 빼기
    if (a != b) seg.update(in[a] + 1, in[b], 1);
}

// 경로 합 쿼리
ll pathQuery(int a, int b) {
    ll ret = 0;
    while (top[a] ^ top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret += seg.query(in[st], in[a]);
        a = par_[st];
    }
    if (dep[a] > dep[b]) swap(a, b); // a가 LCA 쪽
    if (a != b) ret += seg.query(in[a] + 1, in[b]);
    return ret;
}

void solve() {
    cin >> n >> m;

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

    while (m--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'P') {
            pathUpdate(a, b);
        }
        else { // 'Q'
            cout << pathQuery(a, b) << '\n';
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
