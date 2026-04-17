// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long

/*
세그비츠 공부
https://justicehui.github.io/hard-algorithm/2019/10/10/segment-tree-beats/

*/

const ll FULL = (1LL << 30) - 1;

struct Node {
    ll mn, andV, orV, lazyAnd, lazyOr;
};

ll arr[500005];
Node tree[2000005];

Node f(Node a, Node b) {
    return {min(a.mn, b.mn), a.andV & b.andV, a.orV | b.orV, FULL, 0};
}

Node init(int node, int s, int e) {
    if(s == e)
        return tree[node] = {arr[s], arr[s], arr[s], FULL, 0};
    int m = s + e >> 1;
    return tree[node] = f(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

void applyAnd(int node, ll x) {
    tree[node].mn &= x;
    tree[node].andV &= x;
    tree[node].orV &= x;
    tree[node].lazyAnd &= x;
    tree[node].lazyOr &= x;
}

void applyOr(int node, ll x) {
    tree[node].mn |= x;
    tree[node].andV |= x;
    tree[node].orV |= x;
    tree[node].lazyOr |= x;
}

void push(int node, int s, int e) {
    if(s == e) return;
    for(int c : {node * 2, node * 2 + 1}) {
        if(tree[node].lazyAnd != FULL) applyAnd(c, tree[node].lazyAnd);
        if(tree[node].lazyOr != 0) applyOr(c, tree[node].lazyOr);
    }
    tree[node].lazyAnd = FULL;
    tree[node].lazyOr = 0;
}

void updateAnd(int node, int s, int e, int l, int r, ll x) {
    if(r < s || e < l) return;
    if(l <= s && e <= r) {
        if(((tree[node].andV ^ tree[node].orV) & ~x) == 0) {
            applyAnd(node, x);
            return;
        }
    }
    push(node, s, e);
    int m = s + e >> 1;
    updateAnd(node * 2, s, m, l, r, x);
    updateAnd(node * 2 + 1, m + 1, e, l, r, x);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

void updateOr(int node, int s, int e, int l, int r, ll x) {
    if(r < s || e < l) return;
    if(l <= s && e <= r) {
        if(((tree[node].andV ^ tree[node].orV) & x) == 0) {
            applyOr(node, x);
            return;
        }
    }
    push(node, s, e);
    int m = s + e >> 1;
    updateOr(node * 2, s, m, l, r, x);
    updateOr(node * 2 + 1, m + 1, e, l, r, x);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

ll getMin(int node, int s, int e, int l, int r) {
    if(r < s || e < l)
        return LLONG_MAX;
    if(l <= s && e <= r)
        return tree[node].mn;
    push(node, s, e);
    int m = s + e >> 1;
    return min(getMin(node * 2, s, m, l, r),
               getMin(node * 2 + 1, m + 1, e, l, r));
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, 1, n);
    int q;
    cin >> q;
    while(q--) {
        char t;
        int l, r; ll x;
        cin >> t;
        if(t == '?') {
            cin >> l >> r;
            cout << getMin(1, 1, n, l, r) << '\n';
        }
        else {
            cin >> l >> r >> x;
            if(t == '&') updateAnd(1, 1, n, l, r, x);
            else updateOr(1, 1, n, l, r, x);
        }
    }
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
