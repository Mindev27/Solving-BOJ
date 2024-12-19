#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
ll arr[1000005];
ll seg[4000050];
ll lazy_arr[4000050];

ll build(int node, int start, int end) {
    if (start == end) {
        seg[node] = arr[start];
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    return seg[node];
}

void propagate(int node, int start, int end) {
    if (lazy_arr[node] != 0) {
        seg[node] += (end - start + 1) * lazy_arr[node];
        if (start != end) {
            lazy_arr[2 * node] += lazy_arr[node];
            lazy_arr[2 * node + 1] += lazy_arr[node];
        }
        lazy_arr[node] = 0;
    }
}

void update_range(int node, int start, int end, int l, int r, ll val) {
    propagate(node, start, end);
    if (r < start || end < l)
        return;
    if (l <= start && end <= r) {
        seg[node] += (end - start + 1) * val;
        if (start != end) {
            lazy_arr[2 * node] += val;
            lazy_arr[2 * node + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(2 * node, start, mid, l, r, val);
    update_range(2 * node + 1, mid + 1, end, l, r, val);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

ll query_range(int node, int start, int end, int l, int r) {
    propagate(node, start, end);
    if (r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return seg[node];
    int mid = (start + end) / 2;
    return query_range(2 * node, start, mid, l, r) + query_range(2 * node + 1, mid + 1, end, l, r);
}

void solve() {
    int M, K;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    build(1, 1, N);
    for(int i = 0; i < M + K; i++) {
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            ll val;
            cin >> l >> r >> val;
            update_range(1, 1, N, l, r, val);
        }
        else if(type == 2){
            int l, r;
            cin >> l >> r;
            cout << query_range(1, 1, N, l, r) << "\n";
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
