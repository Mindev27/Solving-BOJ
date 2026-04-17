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

일단 max - (max/d) == min - (min/d) 면 구간을 한번에 처리가능함
*/

struct Node {
    ll mn, mx, sum, lazy;
};

ll arr[100005];
Node tree[400005];

ll fdiv(ll a, ll d) {
    return a >= 0 ? a / d : -((-a + d - 1) / d);
}

Node f(Node a, Node b) {
    return {min(a.mn, b.mn), max(a.mx, b.mx), a.sum + b.sum, 0};
}

Node init(int node, int s, int e) {
    if(s == e)
        return tree[node] = {arr[s], arr[s], arr[s], 0};
    int m = s + e >> 1;
    return tree[node] = f(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

void applyAdd(int node, int s, int e, ll v) {
    tree[node].mn += v;
    tree[node].mx += v;
    tree[node].sum += v * (e - s + 1);
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
        ll dmx = tree[node].mx - fdiv(tree[node].mx, d);
        ll dmn = tree[node].mn - fdiv(tree[node].mn, d);
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

ll getmin(int node, int s, int e, int l, int r) {
    if(r < s || e < l)
        return LLONG_MAX;
    if(l <= s && e <= r)
        return tree[node].mn;
    push(node, s, e);
    int m = s + e >> 1;
    return min(getmin(node * 2, s, m, l, r),
               getmin(node * 2 + 1, m + 1, e, l, r));
}

ll getsum(int node, int s, int e, int l, int r) {
    if(r < s || e < l)
        return 0;
    if(l <= s && e <= r)
        return tree[node].sum;
    push(node, s, e);
    int m = s + e >> 1;
    return getsum(node * 2, s, m, l, r) + getsum(node * 2 + 1, m + 1, e, l, r);
}


void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    init(1, 0, n - 1);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r; ll c;
            cin >> l >> r >> c;
            updateAdd(1, 0, n - 1, l, r, c);
        }
        else if(op == 2) {
            int l, r; ll d;
            cin >> l >> r >> d;
            updateDiv(1, 0, n - 1, l, r, d);
        }
        else if(op == 3) {
            int l, r;
            cin >> l >> r;
            cout << getmin(1, 0, n - 1, l, r) << '\n';
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << getsum(1, 0, n - 1, l, r) << '\n';
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
