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
    int tree[1 << 18]; // 전체 크기
    int sz = 1 << 17;  // 리프 시작인덱스

    void update(int x, int v) {
        x |= sz;
        tree[x] = v; // 리프로 옮겨서 값 바꾸기

        while (x >>= 1) {
            tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
        }
    }

    int query(int l, int r) {
        l |= sz;
        r |= sz;
        int ret = 0;
        while (l <= r) {
            if (l & 1)
                ret = max(ret, tree[l++]);
            if (~r & 1)
                ret = max(ret, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
} seg;

int sz[100005], dep[100005], par[100005], top[100005], in[100005], out[100005];
vector<int> g[100005];   // HLD용 그래프
vector<int> inp[100005]; // 입력용 그래프

int chk[100005];
int revIn[100005]; // revIn[in[v]] = v
int color[100005]; // 0: white, 1: black
const int BIG = 1000000000;

int pv = 0;

// 이걸로 g만들기
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

// 이걸로 sz dep 계산하고 g에서 g[v][0]을 Heavy Edge로 찾아두기
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
    revIn[in[v]] = v;
    for (auto i : g[v]) {
        top[i] = (i == g[v][0] ? top[v] : i);
        dfs2(i);
    }
    out[v] = pv;
}

void update(int v) {
    if (color[v] == 0) {
        color[v] = 1;
        seg.update(in[v], BIG - in[v]);
    }
    else {
        color[v] = 0;
        seg.update(in[v], 0);
    }
}

// 루트 1에서 v까지 경로 상의 첫 번째 검은 정점
int queryPath(int v) {
    int a = 1;
    int ret = 0;
    while (top[a] ^ top[v]) {
        if (dep[top[a]] > dep[top[v]])
            swap(a, v);
        int st = top[v];
        ret = max(ret, seg.query(in[st], in[v]));
        v = par[st];
    }
    if (dep[a] > dep[v])
        swap(a, v);
    ret = max(ret, seg.query(in[a], in[v]));
    if (ret == 0)
        return -1;
    int pos = BIG - ret;
    return revIn[pos];
}

void solve() {
    int n, q;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        g[i].clear();
        inp[i].clear();
        chk[i] = 0;
        sz[i] = dep[i] = par[i] = top[i] = in[i] = out[i] = 0;
        color[i] = 0;
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

    cin >> q;
    while (q--) {
        int op, v;
        cin >> op >> v;
        if (op == 1) {
            update(v);
        }
        else { // op == 2
            cout << queryPath(v) << '\n';
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
