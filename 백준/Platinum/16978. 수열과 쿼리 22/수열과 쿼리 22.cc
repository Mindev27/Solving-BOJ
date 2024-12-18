#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct oneQ
{
    int idx;
    ll val;
};

struct twoQ
{
    int k, l ,r;
};


int N;
ll arr[1000001];
ll seg[4000004];

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

ll update(int node, int start, int end, int idx, ll new_val) {
    if (start == end) {
        arr[idx] = new_val;
        seg[node] = new_val;
    }
    else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, new_val);
        else
            update(2 * node + 1, mid + 1, end, idx, new_val);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    return seg[node];
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return seg[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

void solve() {
    int Q;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    build(1, 1, N);

    vector<oneQ> one;
    vector<pair<int, twoQ>> two;
    int cntTwo = 0;

    cin >> Q;
    while(Q--){
        int type; cin >> type;
        if(type == 1) {
            oneQ x; cin >> x.idx >> x.val;
            one.push_back(x);
        }
        else {
            twoQ x; cin >> x.k >> x.l >> x.r;
            two.push_back({cntTwo++, x});
        }
    }

    sort(two.begin(), two.end(), [&](pair<int, twoQ> a, pair<int, twoQ> b) {
        return a.Y.k < b.Y.k;
    });

    vector<pair<int, ll>> ans;
    
    int j = 0;
    while(j < two.size() && two[j].Y.k == 0) {
        ll temp = query(1, 1, N, two[j].Y.l, two[j].Y.r);
        ans.push_back({two[j].X, temp});
        //cout << two[j].X << ' ' <<  temp << '\n';
        j++;
    }
    for(int i = 0; i < one.size(); i++) {
        // 1번 쿼리 처리하고 
        update(1, 1, N, one[i].idx, one[i].val);

        // k번째까지 2번 쿼리 처리
        while(j < two.size() && two[j].Y.k == i + 1) {
            ll temp = query(1, 1, N, two[j].Y.l, two[j].Y.r);
            ans.push_back({two[j].X, temp});
            //cout << two[j].X << ' ' <<  temp << '\n';
            j++;
        }
    }

    sort(ans.begin(), ans.end(), [&](pair<int, ll> a, pair<int, ll> b) {
        return a.X < b.X;
    });

    for(auto &i : ans) {
        cout << i.Y << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;   
}
