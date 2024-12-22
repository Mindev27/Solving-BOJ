#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Point {
    int x, y, w;
};

struct Node {
    ll sum, rMax, lMax, max;
};

int N;
vector<pii> xx, yy;
vector<Point> p;
vector<pair<int, int>> compX[3005];
Node seg[12005];

void initTree() {
    for (int i = 0; i < 12005; i++) {
        seg[i] = { 0, 0, 0, 0 };
    }
}

Node merge(Node left, Node right) {
    Node ret;
    ret.sum = left.sum + right.sum;
    ret.lMax = max(left.lMax, left.sum + right.lMax);
    ret.rMax = max(right.rMax, right.sum + left.rMax);
    ret.max = max({ left.max, right.max, left.rMax + right.lMax });
    return ret;
}

Node update(int cur, int l, int r, int idx, ll val) {
    if (idx < l || r < idx) return seg[cur];
    if (l == r) {
        seg[cur].sum += val;
        seg[cur].lMax += val;
        seg[cur].rMax += val;
        seg[cur].max += val;
        return seg[cur];
    }
    int mid = (l + r) / 2;
    Node left = update(cur * 2, l, mid, idx, val);
    Node right = update(cur * 2 + 1, mid + 1, r, idx, val);
    seg[cur] = merge(left, right);
    return seg[cur];
}

void solve() {
    cin >> N;
    p.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        xx.push_back({ a, i });
        yy.push_back({ b, i });
        p[i].w = c;
    }

    // 좌표압축
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());

    int cnt = 0;
    for (int i = 0; i < xx.size(); i++) {
        if (i > 0 && xx[i - 1].X != xx[i].X) cnt++;
        p[xx[i].Y].x = cnt;
    }

    cnt = 0;
    for (int i = 0; i < yy.size(); i++) {
        if (i > 0 && yy[i - 1].X != yy[i].X) cnt++;
        p[yy[i].Y].y = cnt;
    }

    // x범위에 따라 세그트리 만들기
    for (int i = 0; i < N; i++) {
        compX[p[i].x].push_back({ p[i].y, p[i].w });
    }

    ll res = 0;
    for (int sx = 0; sx < yy.size(); sx++) {
        initTree();
        for (int ex = sx; ex < xx.size(); ex++) {
            for (auto [y, w] : compX[ex]) {
                update(1, 0, N - 1, y, w);
            }
            res = max(res, seg[1].max);
        }
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
