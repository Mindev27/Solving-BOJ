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

struct Node {
    ll mn, mx, lazy;
};

ll arr[200005];
Node tree[800005];

Node f(Node a, Node b) {
    return {min(a.mn, b.mn), max(a.mx, b.mx), 0};
}

Node init(int node, int s, int e) {
    if(s == e)
        return tree[node] = {arr[s], arr[s], 0};
    int m = s + e >> 1;
    return tree[node] = f(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

void applyAdd(int node, int s, int e, ll v) {
    tree[node].mn += v;
    tree[node].mx += v;
    tree[node].lazy += v;
}

void push(int node, int s, int e) {
    if(tree[node].lazy == 0 || s == e)
        return;
    int m = s + e >> 1;
    applyAdd(node * 2, s, m, tree[node].lazy);
    applyAdd(node * 2 + 1, m + 1, e, tree[node].lazy);
    tree[node].lazy = 0;
}

void updateAdd(int node, int s, int e, int l, int r, ll v) {
    if(r < s || e < l)
        return;
    if(l <= s && e <= r) {
        applyAdd(node, s, e, v);
        return;
    }
    push(node, s, e);
    int m = s + e >> 1;
    updateAdd(node * 2, s, m, l, r, v);
    updateAdd(node * 2 + 1, m + 1, e, l, r, v);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
    tree[node].lazy = 0;
}

void updateDiv(int node, int s, int e, int l, int r, ll d) {
    if(r < s || e < l)
        return;
    if(l <= s && e <= r) {
        ll dmx = tree[node].mx - tree[node].mx / d;
        ll dmn = tree[node].mn - tree[node].mn / d;
        if(dmx == dmn) {
            applyAdd(node, s, e, -dmx);
            return;
        }
    }
    push(node, s, e);
    int m = s + e >> 1;
    updateDiv(node * 2, s, m, l, r, d);
    updateDiv(node * 2 + 1, m + 1, e, l, r, d);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
    tree[node].lazy = 0;
}

ll getMax(int node, int s, int e, int l, int r) {
    if(r < s || e < l)
        return LLONG_MIN;
    if(l <= s && e <= r)
        return tree[node].mx;
    push(node, s, e);
    int m = s + e >> 1;
    return max(getMax(node * 2, s, m, l, r),
               getMax(node * 2 + 1, m + 1, e, l, r));
}


void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    init(1, 0, n - 1);
    while(q--) {
        int t, l, r; ll x;
        cin >> t >> l >> r >> x;
        if(t == 0) {
            updateAdd(1, 0, n - 1, l, r, x);
        }
        else if(t == 1) {
            updateDiv(1, 0, n - 1, l, r, x);
        }
        else {
            cout << getMax(1, 0, n - 1, l, r) << '\n';
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
