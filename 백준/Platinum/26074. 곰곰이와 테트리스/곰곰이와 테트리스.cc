#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double, double>

int N, M;
int a[8];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < 8; i++) {
        int x; cin >> x;
    }

    if ((N == 1 && M == 2) || (N == 2 && M == 1)) {
        cout << "ChongChong";
    }
    else {
        cout << "GomGom";
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