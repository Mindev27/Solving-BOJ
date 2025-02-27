#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

void solve() {
    int N;
    cin >> N;
    vector<pair<long double, int>> v;

    for(int i = 1; i <= N; i++) {
        long double x, y, s; cin >> x >> y >> s;
        long double dist = sqrt(x*x + y*y);
        long double time = dist / s;

        v.push_back({time, i});
    }

    sort(v.begin(), v.end());

    for(auto &i : v) cout << i.Y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
