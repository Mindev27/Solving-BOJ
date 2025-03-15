#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N;
vector<int> a;

void solve() {
    cin >> N;
    a.resize(N);
    for (int& i : a) cin >> i;

    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int cur = a[i];
        ans += 180 * (cur); // 변에 놓기
    }

    ans += 180 * (a[N - 1] - 2);

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
