#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N;
vector<ll> h;

void solve() {
    h.push_back(0);
    h.push_back(1);

    ll cur = 1;
    ll add = 2;
    int cnt = 2;

    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j < cnt; j++) {
            cur += add;
            h.push_back(cur);
        }
        add *= 2;
        cnt++;
    }

    int caseNum = 1;
    while (cin >> N) {
        cout << "Case " << caseNum++ << ": ";
        cout << h[N] << '\n';
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
