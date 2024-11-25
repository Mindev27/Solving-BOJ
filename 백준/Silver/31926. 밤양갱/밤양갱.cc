#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
    ll N; cin >> N;
    ll x = 1, K = 0;
    while((x << K) < N) {
        K++;
    }
    if(N == 1 || N == 2 || (x << K) == N) cout << K + 10;
    else cout << K + 9;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}