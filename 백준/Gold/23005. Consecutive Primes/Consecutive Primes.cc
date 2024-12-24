#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MAX_P = 10000000;
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

    ll sqrtZ = sqrt(Z);
    auto it = upper_bound(primes.begin(), primes.end(), sqrtZ);
    int startIdx = distance(primes.begin(), it) - 5;

    ll res = 0;
    for (int i = max(0, startIdx); i < primes.size() - 1; i++) {
        if (primes[i] > sqrt(Z)) break;
        ll product = primes[i] * primes[i + 1];
        if (product <= Z) res = product;
        else break;
    }

    cout << res << "\n";
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
