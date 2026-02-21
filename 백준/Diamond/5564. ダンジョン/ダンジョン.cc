// Writer : exzile_27
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

/*
그냥 주유소 따라하긴데
어차피 샘을 지나왔으면 거기서 먹을 수 있었다는것

그러면 부족할때 내가 지금까지 본 샘중에 이득인걸 취하자.
근데 상한이 있네.. 
*/

// 레이지세그
struct Seg {
    int n, sz;
    vector<ll> mx, lz;

    Seg() {}
    Seg(const vector<ll>& a) { init(a); }

    void init(const vector<ll>& a) {
        sz = (int)a.size() - 1; // 1..sz
        n = 1;
        while (n < sz + 1) n <<= 1;

        mx.assign(2 * n, LLONG_MIN / 4);
        lz.assign(2 * n, 0);

        for (int i = 1; i <= sz; i++) mx[n + i] = a[i];
        for (int i = n - 1; i >= 1; i--) mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }

    void push(int i) {
        if (lz[i] == 0) return;
        ll v = lz[i];
        for (int ch : {i << 1, i << 1 | 1}) {
            lz[ch] += v;
            mx[ch] += v;
        }
        lz[i] = 0;
    }

    void add(int ql, int qr, ll v, int i, int l, int r) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            mx[i] += v;
            lz[i] += v;
            return;
        }
        push(i);
        int m = (l + r) >> 1;
        add(ql, qr, v, i << 1, l, m);
        add(ql, qr, v, i << 1 | 1, m, r);
        mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }

    // [l, r) with indices in 1..sz
    void add(int l, int r, ll v) { add(l, r, v, 1, 0, n); }

    ll qmax(int ql, int qr, int i, int l, int r) {
        if (qr <= l || r <= ql) return LLONG_MIN / 4;
        if (ql <= l && r <= qr) return mx[i];
        push(i);
        int m = (l + r) >> 1;
        return max(qmax(ql, qr, i << 1, l, m),
                    qmax(ql, qr, i << 1 | 1, m, r));
    }

    ll qmax(int l, int r) { return qmax(l, r, 1, 0, n); }
    ll get(int idx) { return qmax(idx, idx + 1); }
};

void solve() {
    int N;
    ll H;
    cin >> N >> H;

    vector<ll> d(N + 1), h(N + 1);
    for (int i = 1; i <= N - 1; i++) cin >> d[i] >> h[i];

    vector<ll> baseHP(N + 1, 0);
    baseHP[1] = H;
    for (int i = 1; i <= N - 1; i++) baseHP[i + 1] = baseHP[i] - d[i];
    
    

    Seg seg(baseHP);

    priority_queue<pair<ll,int>> pq;

    ll ans = 0;

    for (int i = 1; i <= N - 1; i++) {
        pq.push({h[i], i}); 
        int curFloor = i + 1;

        while (seg.get(curFloor) <= 0) {
            auto [key, pos] = pq.top(); pq.pop();

            ll mxHP = seg.qmax(pos, N + 1); 
            ll eff = min(h[pos], H - mxHP);

            if (eff <= 0) continue;

            if (eff != key) {
                pq.push({eff, pos});
                continue;
            }

            ll curHP = seg.get(curFloor);

            ll need = (1 - curHP + eff - 1) / eff;

            ll can = (H - mxHP) / eff;

            ll use = min(need, can);
            if (use <= 0) continue;

            ans += use;

            seg.add(pos, N + 1, use * eff);

            pq.push({eff, pos});
        }
    }

    cout << ans << "\n";
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