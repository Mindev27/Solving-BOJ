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
    int tree[1 << 18]; // 전체 크기
    int sz = 1 << 17;  // 리프 시작인덱스

    void update(int x, int v) {
        x |= sz;
        tree[x] = v; // 리프로 옮겨서 값 바꾸기

        // 세그 업데이트
        while(x >>= 1) {
            tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
        }
    }

    int query(int l, int r) {
        l |= sz; r |= sz;
        int ret = 0;
        while(l <= r) {
            if(l & 1) ret = max(ret, tree[l++]);
            if(~r & 1) ret = max(ret, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
}seg;

int sz[100005], dep[100005], par[100005], top[100005], in[100005], out[100005];
vector<int> g[100005];   // HLD용 그래프
vector<int> inp[100005]; // 입력용 그래프

int eu[100005], ev[100005], ew[100005];

int chk[100005];

// 이걸로 g만들기
void dfs(int v = 1) {
    chk[v] = 1;
    for(auto i : inp[v]) {
        if(chk[i]) continue;
        chk[i] = 1;
        g[v].push_back(i);
        dfs(i);
    }
}

// 이걸로 sz dep 계산하고 g에서 g[v][0]을 Heavy Edge로 찾아두기
void dfs1(int v = 1) {
    sz[v] = 1;
    for(auto &i : g[v]) {
        dep[i] = dep[v] + 1; par[i] = v;
        dfs1(i); sz[v] += sz[i];
        // 항상 0번째가 Heavy Edge
        if(sz[i] > sz[g[v][0]]) swap(i, g[v][0]); 
    }
}

int pv = 0;
void dfs2(int v = 1) {
    in[v] = ++pv;
    for(auto i : g[v]) {
        top[i] = (i == g[v][0] ? top[v] : i);
        dfs2(i);
    }
    out[v] = pv;
}

void update(int v, int w) {
    seg.update(in[v], w);
}

int query(int a, int b) {
    int ret = 0;
    while(top[a] ^ top[b]) { // 같을때까지 
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, seg.query(in[st], in[a]));
        a = par[st];
    }
    if(dep[a] > dep[b]) swap(a,b);
    if(a != b) ret = max(ret, seg.query(in[a] + 1, in[b]));
    return ret;
}

void solve() {
    int n, q;
    cin >> n;

    
    for(int i = 1; i < n; i++){
        int s, e, w;
        cin >> s >> e >> w;
        inp[s].push_back(e);
        inp[e].push_back(s);
        eu[i] = s;
        ev[i] = e;
        ew[i] = w;
    }

    dfs(); dfs1(); dfs2();
    
    for (int i = 1; i < n; i++) {
        int u = eu[i], v = ev[i];
        int child = (par[u] == v ? u : v);
        update(child, ew[i]);
    }

    cin >> q;
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) {
            int idx = a;
            int u = eu[idx], v = ev[idx];
            int child = (par[u] == v ? u : v);
            update(child, b);
        }
        else {
            cout << query(a, b) << '\n';
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