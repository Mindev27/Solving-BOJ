#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>


void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n), diff;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = b;
        if (a > b) diff.push_back(a - b);
    }

    sort(diff.rbegin(), diff.rend());
    int upgrade = (x - 1000 * n) / 4000;

    for (int i = 0; i < min(upgrade, (int)diff.size()); i++)
        v[i] += diff[i];

    cout << accumulate(v.begin(), v.end(), 0);
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
