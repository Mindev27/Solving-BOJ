#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>


void solve() {
    int n;
    cin >> n;
    map<int, int> x, y;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
    }
    int ans = 0;
    for (auto [k, v] : x) if (v >= 2) ans++;
    for (auto [k, v] : y) if (v >= 2) ans++;
    cout << ans;
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
