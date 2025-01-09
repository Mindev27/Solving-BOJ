#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int h, w;
char mp[35][35];
bool vst[35][35];
int d[35][35];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

vector<pii> S, M, R;

bool inRange(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

int BFSdist(int sx, int sy, int ex, int ey) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            vst[i][j] = false;
            d[i][j] = -1;
        }
    }

    queue<pii> q;
    q.push({ sx, sy });
    vst[sx][sy] = true;
    d[sx][sy] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.X == ex && cur.Y == ey)
            return d[ex][ey];

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i], ny = cur.Y + dy[i];

            if (!inRange(nx, ny)) continue;
            if (vst[nx][ny]) continue;
            if (mp[nx][ny] == 'X') continue;
            if (mp[nx][ny] == 'R' && (nx != ex || ny != ey)) continue;

            vst[nx][ny] = true;
            d[nx][ny] = d[cur.X][cur.Y] + 1;
            q.push({ nx, ny });
        }
    }

    return -1;
}

void solve(int t) {
    cin >> h >> w;

    S.clear();
    M.clear();
    R.clear();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') S.push_back({ i, j });
            if (mp[i][j] == 'M') M.push_back({ i, j });
            if (mp[i][j] == 'R') R.push_back({ i, j });
        }
    }

    cout << "Data Set " << t << ":\n";

    if (S.empty() || M.empty() || R.empty()) {
        cout << "Impossible\n";
        return;
    }

    ll ans = LLONG_MAX;
    bool possible = false;

    for (auto mm : M) {
        for (auto rr : R) {
            ll total = 0;
            bool canReach = true;

            for (auto ss : S) {
                int sm = BFSdist(ss.X, ss.Y, mm.X, mm.Y);
                int mr = BFSdist(mm.X, mm.Y, rr.X, rr.Y);
                int rs = BFSdist(rr.X, rr.Y, ss.X, ss.Y);

                if (sm < 0 || mr < 0 || rs < 0) {
                    canReach = false;
                    break;
                }

                total += sm + mr + rs;
                if (total > ans) break;
            }

            if (canReach) {
                possible = true;
                ans = min(ans, total);
            }
        }
    }

    if (!possible)
        cout << "Impossible\n";
    else
        cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve(tt);
    }

    return 0;
}
