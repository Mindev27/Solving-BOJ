// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*


*/


void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    if(M < 2 * K) { cout << "Yuto\n"; return; }
    else {
        if((N*M-2*K*K) % 2 == 1) cout << "Yuto\n";
        else cout << "Platina\n";
    }
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