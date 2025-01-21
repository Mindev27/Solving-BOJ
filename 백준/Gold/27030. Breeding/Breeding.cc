#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

unordered_map<int, ll> dp;

ll get(int x) {
    if (x == 1) return 1;
    if (dp.count(x)) return dp[x];

    ll ways = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ways += get(i);
            if (i != x / i) ways += get(x / i);
        }
    }
    dp[x] = ways;
    return ways;
}


void solve() {
    int N;
    cin >> N;
    cout << get(N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1;tt <= Tc;tt++) {
        solve();
    }

    return 0;
}
