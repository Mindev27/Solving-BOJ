#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

ll sum = 0;
int N;
int a[100005];
ll prefix[100005];
ll ans = -1;

ll get(int L, int R) {
    return prefix[R] - prefix[L];
}

void solve() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        a[i] = a[i + N] = x;
        sum += x;
    }

    for (int i = 1; i <= 2 * N; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int l = 0, r = 0; l <= N; l++) {
        while (r + 1 < 2 * N && get(l, r + 1) <= sum / 2) r++;

        ans = max(ans, get(l, r));
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
