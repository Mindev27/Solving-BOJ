#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

void solve() {
    ll W, H, f;
    ll c;
    ll x1, y1, x2, y2;
    cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;

    ll m = min(f, W - f);
    ll width = (x2 - x1);  // 접힌 상태에서 가로
    ll cover = 0;      // 실제로 칠해지는 가로

    if (x2 <= m) {
        cover = 2 * width;
    }
    else if (x1 >= m) {
        cover = width;
    }
    else {
        cover = 2 * (m - x1) + (x2 - m);
    }

    ll height = (y2 - y1);
    ll layers = c + 1; 

    ll area = cover * height * layers;
    ll totArea = (ll)W * H;

    cout << totArea - area << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
