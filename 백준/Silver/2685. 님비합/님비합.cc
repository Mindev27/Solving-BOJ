#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

void solve() {
    int B, X, Y, res = 0, p = 1;
    cin >> B >> X >> Y;
    while (X || Y) {
        int d = (X % B + Y % B) % B;
        res += d * p;
        X /= B; Y /= B; p *= B;
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}