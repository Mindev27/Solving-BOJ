// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
층 높이가 h로 같으면 쿼리마다 한꺼번에 처리가되잖아
diff찍고 imos 느낌으로 하면 될듯


*/

// exzile_27 세그 템플릿

const int MAXN = 3000000;

int n, q;
ll a[MAXN + 1];
ll seg[4 * MAXN + 5];

// 여기만 바꾸면 됨 (min, max, gcd 등)
ll mergeVal(ll x, ll y) {
    return x + y; 
}

// 범위 밖 리턴값 (합이면 0 min이면 INF)
ll id = 0;

// build(1, 1, n);
void build(int node, int s, int e) {
    if (s == e) {
        seg[node] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    build(node << 1, s, mid);
    build(node << 1 | 1, mid + 1, e);
    seg[node] = mergeVal(seg[node << 1], seg[node << 1 | 1]);
}

void update(int node, int s, int e, int idx, ll val) {
    if (s == e) {
        seg[node] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (idx <= mid) update(node << 1, s, mid, idx, val);
    else update(node << 1 | 1, mid + 1, e, idx, val);
    seg[node] = mergeVal(seg[node << 1], seg[node << 1 | 1]);
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return id;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) >> 1;
    ll leftVal = query(node << 1, s, mid, l, r);
    ll rightVal = query(node << 1 | 1, mid + 1, e, l, r);
    return mergeVal(leftVal, rightVal);
}

int kth(int node, int s, int e, ll k) {
    if (s == e) return s;
    int mid = (s + e) >> 1;
    if (seg[node << 1] >= k) return kth(node << 1, s, mid, k);
    else return kth(node << 1 | 1, mid + 1, e, k - seg[node << 1]);
}

const int MAXH = 3000000;
int diff[MAXH + 5];
int score[MAXH + 5];
int colH[300000 + 5];

void solve() {
    int N;
    cin >> N;

    int plusScore[3] = {1, 2, 5};

    int maxH = 0;

    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x > 0) {
                int start = colH[i] + 1;
                int end = colH[i] + x;

                diff[start] += plusScore[c];
                diff[end + 1] -= plusScore[c];
            }
            colH[i] += x;
            if (colH[i] > maxH) maxH = colH[i];
        }
    }

    for (int h = 1; h <= maxH; h++) {
        score[h] = score[h - 1] + diff[h];
    }

    n = maxH;
    for (int i = 1; i <= n; i++) a[i] = 1;
    build(1, 1, n);

    int M;
    cin >> M;
    while (M--) {
        int h;
        cin >> h;
        if (h <= 0 || h > seg[1]) {
            cout << 0 << '\n';
            continue;
        }

        int idx = kth(1, 1, n, h);

        cout << score[idx] << '\n';

        update(1, 1, n, idx, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}