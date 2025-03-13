#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

ll N, L, K = -1;
ll cnt = 0;

void solve() {
    cin >> N >> L;
    for (int i = L; i <= 100; i++) {
        ll x = N - (i * (i - 1) / 2);
        if (x < 0) continue;
        if (x % i == 0) {
            K = x / i;
            cnt = i;
            break;
        }
    }

    if (K == -1) cout << "-1\n";
    else {
        for (int i = 0; i < cnt; i++) {
            cout << K + i << ' ';
        }
    }
    cout << '\n';
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
