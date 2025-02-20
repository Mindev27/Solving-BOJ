/*
정렬 누적합 O(NlogN + Q)

*/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N, Q;
vector<int> v;
int prefix[300005]; // 1based

void solve() {
    cin >> N >> Q;
    v.resize(N);
    for(int &i : v) cin >> i;

    sort(v.begin(), v.end());

    memset(prefix, 0, sizeof(prefix));
    for(int i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + v[i-1];
    }

    // for(int i = 1; i <= N; i++) {
    //     cout << prefix[i] << ' ';
    // }
    // cout << '\n';

    while(Q--) {
        int l, r; cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << '\n';
    }
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
