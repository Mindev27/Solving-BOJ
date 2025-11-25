#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

ll n, l, r;
vector<int> v;

void solve() {
    cin >> n >> l >> r;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<int> left;
    for (int i = 1; i <= r; i++) {
        left.push_back(v[i]);
    }

    sort(left.begin(), left.end());

    ll sum1 = 0;
    for (int i = 0; i < r - l + 1; i++) {
        sum1 += left[i];
    }

    vector<int> right;
    for (int i = l; i <= n; i++) {
        right.push_back(v[i]);
    }

    sort(right.begin(), right.end());

    ll sum2 = 0;
    for (int i = 0; i < r - l + 1; i++) {
        sum2 += right[i];
    }

    cout << min(sum1, sum2) << '\n';
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