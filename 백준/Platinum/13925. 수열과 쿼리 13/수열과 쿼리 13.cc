#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const ll MOD = 1000000007;

ll N, M, arr[1000005];
ll seg[4000005], lazyA[4000005], lazyB[4000005];

ll addmod(ll x, ll y) { return (x + y) % MOD; }
ll mulmod(ll x, ll y) { return (x % MOD) * (y % MOD) % MOD; }


void build(int n, int s, int e) {
    if (s == e) {
        seg[n] = arr[s] % MOD;
        lazyA[n] = 1;
        lazyB[n] = 0;
        return;
    }
    int mid = (s + e) / 2;
    build(n * 2, s, mid);
    build(n * 2 + 1, mid + 1, e);
    seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % MOD;
    lazyA[n] = 1;
    lazyB[n] = 0;
}

void applyNode(int n, int s, int e, ll A, ll B) {
    seg[n] = addmod(mulmod(seg[n], A), mulmod((e - s + 1), B));
    lazyA[n] = mulmod(lazyA[n], A);
    lazyB[n] = addmod(mulmod(lazyB[n], A), B);
}

void pushDown(int node, int s, int e) {
    if (s == e) return;
    int mid = (s + e) / 2;

    applyNode(node * 2, s, mid, lazyA[node], lazyB[node]);
    applyNode(node * 2 + 1, mid + 1, e, lazyA[node], lazyB[node]);
    lazyA[node] = 1; lazyB[node] = 0;
}

void update(int node, int s, int e, int l, int r, ll A, ll B) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        applyNode(node, s, e, A, B);
        return;
    }
    pushDown(node, s, e);
    int m = (s + e) / 2;
    update(node * 2, s, m, l, r, A, B);
    update(node * 2 + 1, m + 1, e, l, r, A, B);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    pushDown(node, s, e);
    int mid = (s + e) / 2;
    return (query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r)) % MOD;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    build(1, 1, N);

    cin >> M;
    while (M--) {
        int t; cin >> t;
        if (t == 4) {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, N, x, y) << "\n";
        }
        else {
            int x, y; ll v;
            cin >> x >> y >> v;
            if (t == 1) update(1, 1, N, x, y, 1, v % MOD);
            else if (t == 2) update(1, 1, N, x, y, v % MOD, 0);
            else if (t == 3) update(1, 1, N, x, y, 0, v % MOD);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
