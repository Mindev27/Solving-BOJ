#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*

*/

const int MAX = 500005;
const ll INF = 4e18;

struct Market {
    int t, l, m, idx;
};

int n, u, d, s;
Market a[MAX];
int xs[MAX], xCnt;

ll p[MAX], b[MAX], f[MAX], g[MAX];

int segN;
ll seg1[MAX << 2], seg2[MAX << 2];

int getIdx(int x) {
    return lower_bound(xs + 1, xs + xCnt + 1, x) - xs;
}

void initSeg() {
    segN = 1;
    while (segN < xCnt + 2) segN <<= 1;
    for (int i = 1; i < (segN << 1); i++) {
        seg1[i] = -INF;
        seg2[i] = -INF;
    }
}

void upd(ll* seg, int i, ll v) {
    i += segN - 1;
    seg[i] = max(seg[i], v);
    i >>= 1;
    while (i) {
        seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
        i >>= 1;
    }
}

ll qry(ll* seg, int l, int r) {
    if (l > r) return -INF;
    l += segN - 1;
    r += segN - 1;
    ll ret = -INF;
    while (l <= r) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (!(r & 1)) ret = max(ret, seg[r--]);
        l >>= 1;
        r >>= 1;
    }
    return ret;
}

bool cmpMarket(Market a, Market b) {
    if (a.t != b.t) return a.t < b.t;
    return a.l < b.l;
}

void solve() {
    cin >> n >> u >> d >> s;

    xs[++xCnt] = s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].l >> a[i].m;
        a[i].idx = i;
        xs[++xCnt] = a[i].l;
    }

    sort(xs + 1, xs + xCnt + 1);
    xCnt = unique(xs + 1, xs + xCnt + 1) - (xs + 1);

    sort(a + 1, a + n + 1, cmpMarket);

    initSeg();

    int home = getIdx(s);
    upd(seg1, home, 1LL * d * s);
    upd(seg2, home, -1LL * u * s);

    int st = 1;
    while (st <= n) {
        int ed = st;
        while (ed <= n && a[ed].t == a[st].t) ed++;

        for (int i = st; i < ed; i++) {
            int pos = getIdx(a[i].l);

            ll v1 = qry(seg1, 1, pos);
            ll v2 = qry(seg2, pos, xCnt);

            b[i] = max(v1 - 1LL * d * a[i].l, v2 + 1LL * u * a[i].l) + a[i].m;
        }

        for (int i = st; i < ed; i++) {
            f[i] = b[i];
            if (i > st) {
                f[i] = max(f[i], f[i - 1] - 1LL * d * (a[i].l - a[i - 1].l) + a[i].m);
            }
        }

        for (int i = ed - 1; i >= st; i--) {
            g[i] = b[i];
            if (i + 1 < ed) {
                g[i] = max(g[i], g[i + 1] - 1LL * u * (a[i + 1].l - a[i].l) + a[i].m);
            }
        }

        for (int i = st; i < ed; i++) {
            p[i] = max(f[i], g[i]);
        }

        for (int i = st; i < ed; i++) {
            int pos = getIdx(a[i].l);
            upd(seg1, pos, p[i] + 1LL * d * a[i].l);
            upd(seg2, pos, p[i] - 1LL * u * a[i].l);
        }

        st = ed;
    }

    ll ans = max(qry(seg1, 1, home) - 1LL * d * s,
                 qry(seg2, home, xCnt) + 1LL * u * s);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;

    while (Tc--) solve();

    return 0;
}