#include "weirdtree.h"
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

const int MAXN = 300005;

struct Node {
    ll mx, mx2, cntMx, sum;
};

int N_;
int arr_[MAXN];
Node tree[MAXN * 4];

static Node f(const Node &a, const Node &b) {
    Node r;
    r.sum = a.sum + b.sum;
    if(a.mx == b.mx) {
        r.mx = a.mx;
        r.cntMx = a.cntMx + b.cntMx;
        r.mx2 = max(a.mx2, b.mx2);
    }
    else if(a.mx > b.mx) {
        r.mx = a.mx;
        r.cntMx = a.cntMx;
        r.mx2 = max(a.mx2, b.mx);
    }
    else {
        r.mx = b.mx;
        r.cntMx = b.cntMx;
        r.mx2 = max(a.mx, b.mx2);
    }
    return r;
}

static void buildTree(int node, int s, int e) {
    if(s == e) {
        tree[node] = { (ll)arr_[s], LLONG_MIN, 1, (ll)arr_[s] };
        return;
    }
    int m = (s + e) >> 1;
    buildTree(node * 2, s, m);
    buildTree(node * 2 + 1, m + 1, e);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

static void applyChmin(int node, ll v) {
    if(tree[node].mx <= v) return;
    tree[node].sum -= tree[node].cntMx * (tree[node].mx - v);
    tree[node].mx = v;
}

static void push(int node) {
    for(int c : {node * 2, node * 2 + 1}) {
        if(tree[c].mx > tree[node].mx) {
            applyChmin(c, tree[node].mx);
        }
    }
}

static void updateChmin(int node, int s, int e, int l, int r, ll v) {
    if(r < s || e < l || tree[node].mx <= v) return;
    if(l <= s && e <= r && tree[node].mx2 < v) {
        applyChmin(node, v);
        return;
    }
    push(node);
    int m = (s + e) >> 1;
    updateChmin(node * 2, s, m, l, r, v);
    updateChmin(node * 2 + 1, m + 1, e, l, r, v);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

static void pointSet(int node, int s, int e, int i, ll x) {
    if(s == e) {
        tree[node] = { x, LLONG_MIN, 1, x };
        return;
    }
    push(node);
    int m = (s + e) >> 1;
    if(i <= m) pointSet(node * 2, s, m, i, x);
    else pointSet(node * 2 + 1, m + 1, e, i, x);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

static ll querySum(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node].sum;
    push(node);
    int m = (s + e) >> 1;
    return querySum(node * 2, s, m, l, r) + querySum(node * 2 + 1, m + 1, e, l, r);
}

static ll queryMax(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node].mx;
    push(node);
    int m = (s + e) >> 1;
    return max(queryMax(node * 2, s, m, l, r), queryMax(node * 2 + 1, m + 1, e, l, r));
}

static ll calcCost(int node, int s, int e, int l, int r, ll v) {
    if(r < s || e < l || tree[node].mx <= v) return 0;
    if(l <= s && e <= r && tree[node].mx2 < v) {
        return tree[node].cntMx * (tree[node].mx - v);
    }
    push(node);
    int m = (s + e) >> 1;
    return calcCost(node * 2, s, m, l, r, v) + calcCost(node * 2 + 1, m + 1, e, l, r, v);
}

static ll queryCntVal(int node, int s, int e, int l, int r, ll V) {
    if(r < s || e < l || tree[node].mx < V) return 0;
    if(l <= s && e <= r) {
        if(tree[node].mx == V) return tree[node].cntMx;
        if(tree[node].mx2 < V) return 0;
    }
    push(node);
    int m = (s + e) >> 1;
    return queryCntVal(node * 2, s, m, l, r, V) + queryCntVal(node * 2 + 1, m + 1, e, l, r, V);
}

static void decLeftmost(int node, int s, int e, int l, int r, ll V, ll &k) {
    if(k <= 0) return;
    if(r < s || e < l || tree[node].mx < V) return;
    if(s == e) {
        if(tree[node].mx == V) {
            tree[node].mx -= 1;
            tree[node].sum -= 1;
            k -= 1;
        }
        return;
    }
    push(node);
    int m = (s + e) >> 1;
    decLeftmost(node * 2, s, m, l, r, V, k);
    decLeftmost(node * 2 + 1, m + 1, e, l, r, V, k);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}


void initialise(int N, int Q, int h[]) {
    N_ = N;
    for(int i = 1; i <= N; i++) arr_[i] = h[i];
    buildTree(1, 1, N);
}

void cut(int l, int r, int k) {
    ll kk = k;
    ll M = queryMax(1, 1, N_, l, r);
    if(M == 0) return;
    ll lo = 0, hi = M;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if(calcCost(1, 1, N_, l, r, mid) <= kk) hi = mid;
        else lo = mid + 1;
    }
    ll V = lo;
    ll cost = calcCost(1, 1, N_, l, r, V);
    updateChmin(1, 1, N_, l, r, V);
    kk -= cost;
    if(V > 0 && kk > 0) {
        decLeftmost(1, 1, N_, l, r, V, kk);
    }
}

void magic(int i, int x) {
    pointSet(1, 1, N_, i, (ll)x);
}

long long int inspect(int l, int r) {
    return querySum(1, 1, N_, l, r);
}
