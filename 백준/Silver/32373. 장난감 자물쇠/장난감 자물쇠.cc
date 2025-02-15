#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N, k;
int a[200005];

void solve() {
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    bool flag = true;
    for (int i = 0; i < N; i++) {
        if ((a[i] - i) % k != 0) flag = false;
    }

    cout << (flag ? "Yes" : "No");
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