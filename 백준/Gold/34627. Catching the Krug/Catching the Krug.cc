#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

ll get(ll N, ll rk, ll ck, ll rd, ll cd, int dr, int dc) {
    ll dist = 0;
    if (dr == 1) dist = N - rk;
    if (dr == -1) dist = rk;
    if (dc == 1) dist = N - ck;
    if (dc == -1) dist = ck;

    auto ok = [&](ll j) {
        ll r = rk + dr * j, c = ck + dc * j;
        if (r < 0 || r > N || c < 0 || c > N) return false;
        if (abs(rd - r) > j || abs(cd - c) > j) return false;
        return true;
    };

    vector<ll> cand;
    auto push = [&](ll x) {
        if (0 <= x && x <= dist) cand.push_back(x);
    };

    push(0);
    push(1);
    push(dist);
    push(abs(rd - rk));
    push(abs(cd - ck));

    for (ll x : cand) {
        for (int d = -2; d <= 2; d++)
            if (0 <= x + d && x + d <= dist) cand.push_back(x + d);
    }

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    ll ans = LLONG_MAX;
    for (ll j : cand) if (ok(j)) {
        ans = min(ans, j);
    }

    ll rP = rk + dr * dist;
    ll cP = ck + dc * dist;
    ll need = max(abs(rd - rP), abs(cd - cP));
    return min(ans, need);


}

void solve() {
    ll n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    ll l = get(n, rk, ck, rd,cd, 0, -1);
    ll r = get(n, rk, ck, rd,cd, 0, 1);
    ll u = get(n, rk, ck, rd,cd, -1, 0);
    ll d  = get(n, rk, ck, rd,cd, 1, 0);

    cout << max({l, r, u, d}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}