#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int n, w, h;
vector<pii> p; // 별

// 원이 포스터안인지 체크
bool inBound(double x, double y, double r) {
    return x - r >= 0 && x + r <= w && y - r >= 0 && y + r <= h;
}

// c1이 c2를 포함하는지 확인
bool contains(double x1, double y1, double r1, double x2, double y2, double r2) {
    double d = hypot(x1 - x2, y1 - y2);
    return d + r2 < r1 - 1e-12;
}

void solve() {
    cin >> n >> w >> h;
    p.resize(n);
    for (auto& i : p) cin >> i.X >> i.Y;

    int cnt = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) continue;

            // a, b점으로 만들때 c1원 만들기 중심 x1,y1 반지름 r1
            double x1 = p[a].X, y1 = p[a].Y;
            double r1 = hypot(p[b].X - x1, p[b].Y - y1);

            // c1이 범위 안인지 체크
            if (!inBound(x1, y1, r1)) continue;

            // c , d로 원 만들기 
            for (int c = 0; c < n; c++) {
                if (a == c || b == c) continue;
                for (int d = 0; d < n; d++) {
                    if (a == d || b == d || c == d) continue;

                    // c, d점으로 만들때 c2원 만들기 중심 x2,y2 반지름 r2
                    double x2 = p[c].X, y2 = p[c].Y;
                    double r2 = hypot(p[d].X - x2, p[d].Y - y2);

                    // 범위안이고 포함하면 오케이
                    if (inBound(x2, y2, r2) && contains(x1, y1, r1, x2, y2, r2)) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) {
        solve();
    }
    return 0;
}
