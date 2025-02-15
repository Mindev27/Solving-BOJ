#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N;
vector<tuple<ll, ll, ll>> v; // A C B

// x이하의 개수가 홀수인가?
ll get(ll x) {
    ll ans = 0;
    for (auto& [a, c, b] : v) {
        if (x < a) continue;
        ll cnt = (min(c, x) - a) / b + 1;
        ans += cnt;
    }

    return ans;
}

void solve() {
    cin >> N;
    v.resize(N);
    for (auto& [a, c, b] : v) {
        cin >> a >> c >> b;
    }

    if (get(INT_MAX) % 2 == 0) {
        cout << "NOTHING";
        return;
    }

    ll lo = 0, hi = 1LL * INT_MAX + 1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (get(mid) % 2 == 1) hi = mid;
        else lo = mid;
    }


    cout << hi << ' ' << get(hi) - get(hi - 1);

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