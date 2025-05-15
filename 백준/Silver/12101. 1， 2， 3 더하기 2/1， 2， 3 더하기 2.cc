#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double, double>

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<string> res;
    vector<int> path;

    function<void(int)> dfs = [&](int sum) {
        if (sum == n) {
            string s;
            for (int i = 0; i < path.size(); ++i) {
                if (i) s += '+';
                s += to_string(path[i]);
            }
            res.push_back(s);
            return;
        }
        if (sum > n) return;

        for (int x = 1; x <= 3; ++x) {
            path.push_back(x);
            dfs(sum + x);
            path.pop_back();
        }
        };

    dfs(0);

    if (k >= 1 && k <= (ll)res.size()) {
        cout << res[k - 1] << '\n';
    }
    else {
        cout << -1 << '\n';
    }
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