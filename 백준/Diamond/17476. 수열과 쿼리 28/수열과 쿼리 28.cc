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

구간 내 floor(sqrt(mx)) == floor(sqrt(mn)) 이면 될듯
*/

struct Node {
    ll mn, mx, sum, lazy;
};

ll arr[100005];
Node tree[400005];

ll isqrt(ll a) {
    if(a < 0) return 0;
    ll r = (ll)sqrtl((long double)a);
    while(r * r > a) r--;
    while((r + 1) * (r + 1) <= a) r++;
    return r;
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

void updateSqrt(int node, int s, int e, int l, int r) {
    if(r < s || e < l)
        return;
    if(l <= s && e <= r) {
        ll dmx = tree[node].mx - isqrt(tree[node].mx);
        ll dmn = tree[node].mn - isqrt(tree[node].mn);
        if(dmx == dmn) {
            applyAdd(node, s, e, -dmx);
            return;
        }
    }
    push(node, s, e);
    int m = s + e >> 1;
    updateSqrt(node * 2, s, m, l, r);
    updateSqrt(node * 2 + 1, m + 1, e, l, r);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
    tree[node].lazy = 0;
}

ll getSum(int node, int s, int e, int l, int r) {
    if(r < s || e < l)
        return 0;
    if(l <= s && e <= r)
        return tree[node].sum;
    push(node, s, e);
    int m = s + e >> 1;
    return getSum(node * 2, s, m, l, r) + getSum(node * 2 + 1, m + 1, e, l, r);
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
        int op;
        cin >> op;
        if(op == 1) {
            int l, r; ll x;
            cin >> l >> r >> x;
            updateAdd(1, 1, n, l, r, x);
        }
        else if(op == 2) {
            int l, r;
            cin >> l >> r;
            updateSqrt(1, 1, n, l, r);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << getSum(1, 1, n, l, r) << '\n';
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
