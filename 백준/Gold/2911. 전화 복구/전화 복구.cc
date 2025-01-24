#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

ll N, M;
vector<pll> v;
void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        ll p, c;
        cin >> p >> c;
        v.push_back({ p, c });
    }

    sort(v.begin(), v.end());

    ll ans = v[0].Y;
    for (int i = 1; i < N; i++) {
        if (v[i - 1].Y < v[i].Y) {
            ans += v[i].Y - v[i - 1].Y;
        }
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
