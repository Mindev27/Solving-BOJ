#include "weirdtree.h"
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

const int MAXN = 300005;

struct Node {
    ll max1, max2, cntMax, sum, lazy;
};

int N_;
int arr_[MAXN];
Node tree[MAXN * 4];

static Node merge(const Node &a, const Node &b) {
    Node r{};
    r.sum = a.sum + b.sum;
    r.lazy = 0;
    if(a.max1 == b.max1) {
        r.max1 = a.max1;
        r.cntMax = a.cntMax + b.cntMax;
        r.max2 = max(a.max2, b.max2);
    }
    else if(a.max1 > b.max1) {
        r.max1 = a.max1;
        r.cntMax = a.cntMax;
        r.max2 = max(a.max2, b.max1);
    }
    else {
        r.max1 = b.max1;
        r.cntMax = b.cntMax;
        r.max2 = max(a.max1, b.max2);
    }
    return r;
}

static void buildTree(int node, int s, int e) {
    if(s == e) {
        tree[node] = { (ll)arr_[s], 0, 1, (ll)arr_[s], 0 };
        return;
    }
    int m = (s + e) >> 1;
    buildTree(node * 2, s, m);
    buildTree(node * 2 + 1, m + 1, e);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

static void applyLazy(int node, ll v) {
    tree[node].max1 -= v;
    tree[node].sum -= v * tree[node].cntMax;
    tree[node].lazy += v;
}

static void push(int node, int s, int e) {
    if(tree[node].lazy == 0 || s == e) {
        tree[node].lazy = 0;
        return;
    }
    ll parentMax = tree[node].max1 + tree[node].lazy;
    for(int c : {node * 2, node * 2 + 1}) {
        if(tree[c].max1 == parentMax) {
            applyLazy(c, tree[node].lazy);
        }
    }
    tree[node].lazy = 0;
}

static void pointSet(int node, int s, int e, int i, ll x) {
    if(s == e) {
        tree[node] = { x, 0, 1, x, 0 };
        return;
    }
    push(node, s, e);
    int m = (s + e) >> 1;
    if(i <= m) pointSet(node * 2, s, m, i, x);
    else pointSet(node * 2 + 1, m + 1, e, i, x);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

static ll querySum(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node].sum;
    push(node, s, e);
    int m = (s + e) >> 1;
    return querySum(node * 2, s, m, l, r) + querySum(node * 2 + 1, m + 1, e, l, r);
}

static Node queryRange(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return { 0, 0, 0, 0, 0 };
    if(l <= s && e <= r) return tree[node];
    push(node, s, e);
    int m = (s + e) >> 1;
    Node a = queryRange(node * 2, s, m, l, r);
    Node b = queryRange(node * 2 + 1, m + 1, e, l, r);
    if(a.cntMax == 0) return b;
    if(b.cntMax == 0) return a;
    return merge(a, b);
}

static void updateSubtract(int node, int s, int e, int l, int r, ll value, ll &bonus, ll maxValue) {
    if(value + (bonus > 0 ? 1 : 0) == 0) return;
    if(e < l || s > r) return;
    if(l <= s && e <= r && tree[node].max1 != maxValue) return;

    if(l <= s && e <= r
       && (bonus == 0 || bonus >= (ll)(e - s + 1))
       && (tree[node].max2 == 0 || tree[node].max1 - value - (bonus > 0 ? 1 : 0) > tree[node].max2)) {
        ll dec = value + (bonus > 0 ? 1 : 0);
        applyLazy(node, dec);
        bonus -= (bonus > 0 ? 1 : 0) * tree[node].cntMax;
        return;
    }
    push(node, s, e);
    int m = (s + e) >> 1;
    updateSubtract(node * 2, s, m, l, r, value, bonus, maxValue);
    updateSubtract(node * 2 + 1, m + 1, e, l, r, value, bonus, maxValue);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}


void initialise(int N, int Q, int h[]) {
    N_ = N;
    for(int i = 1; i <= N; i++) arr_[i] = h[i];
    buildTree(1, 1, N);
}

void cut(int l, int r, int k) {
    ll kk = k;
    while(kk > 0) {
        Node q = queryRange(1, 1, N_, l, r);
        if(q.max1 == 0) break;
        if((q.max1 - q.max2) <= kk / q.cntMax) {
            ll cost = (q.max1 - q.max2) * q.cntMax;
            kk -= cost;
            ll bonus = 0;
            updateSubtract(1, 1, N_, l, r, q.max1 - q.max2, bonus, q.max1);
        }
        else {
            ll divResult = kk / q.cntMax;
            ll bonus = kk - divResult * q.cntMax;
            updateSubtract(1, 1, N_, l, r, divResult, bonus, q.max1);
            kk = 0;
        }
    }
}

void magic(int i, int x) {
    pointSet(1, 1, N_, i, (ll)x);
}

long long int inspect(int l, int r) {
    return querySum(1, 1, N_, l, r);
}
