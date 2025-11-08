#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
CD에 k개넣으면 kL + k-1이고 이게 C보다 작거나 같다
그럼 한장에 최대로 C+1/L+1 만큼 들어감
근데 13안되니까 이거 확인해주고 13이면 -1

*/


void solve() {
    ll N, L, C;
    cin >> N >> L >> C;

    ll cap0 = (C + 1) / (L + 1);
    ll cap = (cap0 % 13 == 0) ? cap0 - 1 : cap0;

    if (N <= cap) {
        if (N % 13 == 0) cout << 2 << '\n';
        else cout << 1 << '\n';
        return;
    }

    ll q = N / cap;
    ll r = N % cap;

    if (r == 0) {
        cout << q << '\n';
        return;
    }

    if (r % 13 != 0) {
        cout << q + 1 << '\n';
        return;
    }

    // 예외
    if ((cap % 13 == 1) && (r == cap - 1)) {
        cout << q + 2 << '\n';
    }
    else {
        cout << q + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc=1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}