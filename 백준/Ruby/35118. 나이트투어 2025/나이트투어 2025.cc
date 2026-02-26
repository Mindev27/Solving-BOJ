// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*

*/

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int N, M;
int vis[2026][2026];
int deg[2026][2026];
int initDeg[2026][2026];
int stamp = 0;
pii path[2026 * 2026];
char wbuf[2026 * 2026 * 12];
mt19937 rng(42);

void initBoard() {
    for (int x = 1; x <= N; x++)
        for (int y = 1; y <= M; y++) {
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) cnt++;
            }
            initDeg[x][y] = cnt;
        }
}

void resetDeg() {
    for (int x = 1; x <= N; x++)
        memcpy(deg[x] + 1, initDeg[x] + 1, sizeof(int) * M);
}

bool tryTour(int sx, int sy, ll a, ll b, bool transposed) {
    int total = N * M;
    stamp++;
    resetDeg();

    vis[sx][sy] = stamp;
    for (int i = 0; i < 8; i++) {
        int nx = sx + dx[i], ny = sy + dy[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) deg[nx][ny]--;
    }
    path[0] = {sx, sy};

    int cx = sx, cy = sy;
    int perm[8] = {0,1,2,3,4,5,6,7};
    shuffle(perm, perm + 8, rng);

    for (int step = 1; step < total; step++) {
        int bestDeg = 9, bx = -1, by = -1;
        ll bestDist = -1;
        for (int k = 0; k < 8; k++) {
            int i = perm[k];
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > M || vis[nx][ny] == stamp) continue;
            int d = deg[nx][ny];
            ll vx = 2LL * nx - N - 1, vy = 2LL * ny - M - 1;
            ll dist = a * (ll)M * vx * vx + b * (ll)N * vy * vy;
            if (d < bestDeg || (d == bestDeg && dist > bestDist)) {
                bestDeg = d;
                bestDist = dist;
                bx = nx; by = ny;
            }
        }
        if (bx == -1) return false;
        vis[bx][by] = stamp;
        for (int i = 0; i < 8; i++) {
            int nx = bx + dx[i], ny = by + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) deg[nx][ny]--;
        }
        path[step] = {bx, by};
        cx = bx; cy = by;
    }

    int wlen = 0;
    wbuf[wlen++] = '1'; wbuf[wlen++] = '\n';
    for (int i = 0; i < total; i++) {
        int px = path[i].X, py = path[i].Y;
        if (transposed) swap(px, py);
        int tmp[6], tl;
        tl = 0;
        for (int v = px; v; v /= 10) tmp[tl++] = v % 10;
        for (int j = tl - 1; j >= 0; j--) wbuf[wlen++] = '0' + tmp[j];
        wbuf[wlen++] = ' ';
        tl = 0;
        for (int v = py; v; v /= 10) tmp[tl++] = v % 10;
        for (int j = tl - 1; j >= 0; j--) wbuf[wlen++] = '0' + tmp[j];
        wbuf[wlen++] = '\n';
    }
    fwrite(wbuf, 1, wlen, stdout);
    return true;
}

void solve() {
    int sx, sy;
    cin >> N >> M >> sx >> sy;

    if ((ll)N * M % 2 == 1 && (sx + sy) % 2 == 1) {
        cout << "0\n";
        return;
    }

    initBoard();

    ll area = (ll)N * M;
    int maxK = 6;
    ll budget = max(1LL, 10000000LL / area);

    for (int t = 0; t < 2; t++) {
        ll cnt = 0;
        for (int ki = 0; ki <= maxK && cnt < budget; ki++) {
            for (int kj = 0; kj <= maxK && cnt < budget; kj++) {
                ll a = 1LL << ki, b = 1LL << kj;
                if (tryTour(sx, sy, a, b, t == 1)) return;
                cnt++;
            }
        }
        if (cnt < budget) {
            for (ll r = 0; cnt < budget; r++) {
                ll a = 1LL + (rng() % (1LL << min(maxK, 20)));
                ll b = 1LL + (rng() % (1LL << min(maxK, 20)));
                if (tryTour(sx, sy, a, b, t == 1)) return;
                cnt++;
            }
        }
        swap(N, M);
        swap(sx, sy);
        initBoard();
    }

    cout << "0\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
       // cout << "Case #" << tt << ": ";
       solve();
    }
    return 0;
}