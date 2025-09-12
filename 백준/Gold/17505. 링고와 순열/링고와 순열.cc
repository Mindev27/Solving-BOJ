#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>


void solve() {
    ll N, k; cin >> N >> k;

    vector<ll> v(N, -1);

    ll x = N - 1; // 가장 앞에 놓을때 더해지는 반전개수

    while(k > 0) {
        if(k >= x) {
            k -= x;
            v[(N-1)-x] = x + 1; // 앞에서부터 큰수 채우기

            x--;
        }
        else {
            // 남은 반전이 k개가 되어야함 뒤에서 k번째 즉 N-1-k
            v[N-1-k] = x + 1;
            break;
        }
    }

    ll num = 1;
    for(ll i = 0; i < N; i++) {
        if(v[i] == -1) v[i] = num++;
    }

    for(ll &i : v) cout << i << ' ';
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