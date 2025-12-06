// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

ll gcdll(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve() {

    int n, m;
    cin >> n >> m;
    vector<ll> A(n), B(m);

    ll minA = 4e18, maxA = 0;
    ll minB = 4e18, maxB = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        minA = min(minA, A[i]);
        maxA = max(maxA, A[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
        minB = min(minB, B[i]);
        maxB = max(maxB, B[i]);
    }

    if (minB - maxA >= 0 || maxB - minA <= 0) {
        cout << "NO\n";
        return;
    }

    ll a0 = A[0], b0 = B[0];
    ll g = 0;

    for (int i = 0; i < n; i++) {
        g = gcdll(g, llabs(A[i] - a0));
    }
    for (int i = 0; i < m; i++) {
        g = gcdll(g, llabs(B[i] - b0));
    }
    g = gcdll(g, llabs(b0 - a0));

    if (g == 0) {
        cout << "NO\n";
        return;
    }

    if (g == 1) {
        cout << "YES\n";
        return;
    }

    if (g > n + 1) {
        cout << "NO\n";
        return;
    }

    vector<char> used(g);
    for (int i = 0; i < n; i++) {
        ll r = A[i] % g;
        if (r < 0) r += g;
        if (r > 0) used[r] = 1;
    }

    bool ok = true;
    for (ll i = 1; i < g; i++) {
        if (!used[i]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
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
