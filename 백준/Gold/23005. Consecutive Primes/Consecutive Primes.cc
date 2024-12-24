#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MAX_P = 1030303000;
vector<ll> primes;

void makePrime() {
    vector<bool> isPrime(MAX_P + 1, true);
    for (ll i = 2; i * i <= MAX_P; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= MAX_P; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= MAX_P; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void solve() {
    ll Z;
    cin >> Z;

    ll l = 0;
    ll r = primes.size() - 2;
    ll ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll val = primes[mid] * primes[mid + 1];

        if (val <= Z) {
            ans = val;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    makePrime();

    int Tc;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
