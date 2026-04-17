// Writer : exzile_27
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int MAX = 10005;

int n;

ll a[MAX], pref[MAX * 2 + 5];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    pref[0] = 0;
    for (int i = 0; i < n * 2; i++) pref[i + 1] = pref[i] + a[i % n];

    ll tot = pref[n]; // 전체합

    ll ans = 0;
    for (int st = 0; st < n - 1; st++) { // 시작점
        for (int len = 1; len <= n; len++) { // 길이
            ll r = pref[st + len];
            ll l = pref[len - 1];

            if (r < l) {
                ll diff = l - r;
                ans += (diff + tot - 1) / tot;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;

    while (Tc--) solve();

    return 0;
}