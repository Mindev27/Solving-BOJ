#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
ll seg[4000004];
ll lazy_arr[4000004];

void build(int node, int start, int end) {
    if (start == end) {
        seg[node] = 0;
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}

void propagate(int node, int start, int end) {
    if (lazy_arr[node]) {
        seg[node] = (end - start + 1) - seg[node];
        if (start != end) {
            lazy_arr[2 * node] ^= 1;
            lazy_arr[2 * node + 1] ^= 1;
        }
        lazy_arr[node] = 0;
    }
}

void update_range(int node, int start, int end, int l, int r) {
    propagate(node, start, end);
    if (r < start || end < l)
        return;
    if (l <= start && end <= r) {
        seg[node] = (end - start + 1) - seg[node];
        if (start != end) {
            lazy_arr[2 * node] ^= 1;
            lazy_arr[2 * node + 1] ^= 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(2 * node, start, mid, l, r);
    update_range(2 * node + 1, mid + 1, end, l, r);
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
    cin >> N >> M;
    build(1, 1, N);
    while(M--){
        int O, S, T;
        cin >> O >> S >> T;
        if(O == 0){
            update_range(1, 1, N, S, T);
        }
        else if(O == 1){
            cout << query_range(1, 1, N, S, T) << "\n";
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
