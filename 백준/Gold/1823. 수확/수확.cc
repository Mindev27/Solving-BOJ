#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N;
ll dp[2005][2005];
vector<ll> v;

ll f(int i, int j, int depth) {
    if (i == j) return depth * v[i];

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(f(i + 1, j, depth + 1) + v[i] * depth,
        f(i, j - 1, depth + 1) + v[j] * depth);
}

void solve() {
    cin >> N;
    v.resize(N);
    for (ll& i : v) cin >> i;

    memset(dp, -1, sizeof(dp));

    cout << f(0, N - 1, 1);
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