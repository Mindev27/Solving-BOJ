// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
풀이 보고 풂
*/

const double XS = -10.0, XE = 10.0;
const double YBND = 13.0;
const double DH = 0.01;

int n;
double a, b, c[10];

double fp(double x, double y, double yp) {
    double t = 1.0 + yp * yp;
    double s = 1.0, syp = 0.0, sx = 0.0;
    for (int i = 0; i < n; i++) {
        double d2 = x * x + (y - c[i]) * (y - c[i]);
        double d4 = d2 * d2;
        s += 1.0 / d2;
        syp += (y - c[i]) / d4;
        sx += (x + (y - c[i]) * yp) / d4;
    }
    return 2.0 * t * (sx * yp - syp * t) / s;
}

pair<double, double> shoot(double yp0) {
    double x = XS, y = a, yp = yp0;
    double dose = 0.0;
    int steps = (int)((XE - XS) / DH);
    for (int i = 0; i < steps; i++) {
        if (y < -YBND || y > YBND) return {1e18, y};
        double dd = 0.0;
        for (int j = 0; j < n; j++) {
            double d2 = x * x + (y - c[j]) * (y - c[j]);
            dd += 1.0 / d2;
        }
        dose += DH * (1.0 + dd) * sqrt(1.0 + yp * yp);
        double k1 = DH * yp;
        double l1 = DH * fp(x, y, yp);
        x += DH;
        y += k1;
        yp += l1;
    }
    return {dose, y};
}

void solve() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<double> slopes;
    slopes.push_back(-4.0);
    slopes.push_back(4.0);
    for (int i = 0; i < n; i++)
        slopes.push_back((c[i] - a) / (0.0 - XS));
    sort(slopes.begin(), slopes.end());

    double ans = 1e18;
    for (int i = 0; i + 1 < (int)slopes.size(); i++) {
        double lo = slopes[i], hi = slopes[i + 1];
        for (int it = 0; it < 200; it++) {
            double mid = (lo + hi) / 2.0;
            auto [dose, yend] = shoot(mid);
            if (yend >= b) hi = mid;
            else lo = mid;
        }
        auto [dose, yend] = shoot((lo + hi) / 2.0);
        ans = min(ans, dose);
    }

    cout << fixed << setprecision(6) << ans << "\n";
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);


    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}
