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

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int N;
bool visited[667][667];
pii path[667*667];

int degree(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny])
            cnt++;
    }
    return cnt;
}

void solve() {
    int sx, sy;
    cin >> N >> sx >> sy;

    int total = N * N;
    visited[sx][sy] = true;
    path[0] = {sx, sy};

    int cx = sx, cy = sy;
    bool ok = true;

    for (int step = 1; step < total; step++) {
        int bestDeg = 9, bx = -1, by = -1;
        double bestDist = -1;
        double center = (N + 1) / 2.0;
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]) {
                int d = degree(nx, ny);
                double dist = (nx - center) * (nx - center) + (ny - center) * (ny - center);
                if (d < bestDeg || (d == bestDeg && dist > bestDist)) {
                    bestDeg = d;
                    bestDist = dist;
                    bx = nx;
                    by = ny;
                }
            }
        }
        if (bx == -1) { ok = false; break; }
        visited[bx][by] = true;
        path[step] = {bx, by};
        cx = bx; cy = by;
    }

    if (!ok) {
        cout << "-1 -1\n";
    } else {
        for (int i = 0; i < total; i++)
            cout << path[i].X << ' ' << path[i].Y << '\n';
    }
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