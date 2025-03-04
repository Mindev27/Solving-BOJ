#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N;

void solve() {
    cin >> N;
    vector<int> a, b, c, d;
    a.resize(N), b.resize(N);
    c.resize(N), d.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x.push_back(a[i] + b[j]);
            y.push_back(c[i] + d[j]);
        }
    }

    sort(y.begin(), y.end());
    // cur기준 -cur이 있는지 이분탐색
    ll ans = 0;
    for (int& cur : x) {
        auto stIdx = lower_bound(y.begin(), y.end(), -cur) - y.begin();
        auto edIdx = upper_bound(y.begin(), y.end(), -cur) - y.begin();

        if (y[stIdx] == -cur) ans += edIdx - stIdx;
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}