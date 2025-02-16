#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int L;
vector<int> v;

void solve() {
    cin >> L;
    v.resize(L + 1);
    for(int i = 1; i <= L; i++) {
        cin >> v[i];
    }

    int ans = -1;
    ll maxVal = -LLONG_MAX;
    for(int i = 1; i <= L; i++) {
        ll curSum = 0;
        for(int j = i; j <= L; j += i) {
            curSum += v[j];
        }
        if(curSum > maxVal) {
            ans = i;
            maxVal = curSum;
        }
    }

    if(maxVal <= 0) cout << "0 0";
    else cout << ans << ' ' << maxVal;
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