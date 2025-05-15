#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double, double>

const int MAXN = 1000;
bool isPrime[1000];
vector<int> primes;

void solve() {
    int K;
    cin >> K;

    for (int i = 0; i < primes.size(); i++) {
        int x = primes[i];
        if (x > K) break;
        for (int j = i; j < primes.size(); j++) {
            int y = primes[j];
            if (x + y > K) break;
            int k = K - x - y;
            if (k < y) break;
            if (k < MAXN && isPrime[k]) {
                cout << x << ' ' << y << ' ' << k << "\n";
                return;
            }
        }
    }

    cout << "0\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    fill(isPrime, isPrime + MAXN, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < MAXN; j += i)
            isPrime[j] = false;
    }
    for (int i = 2; i < MAXN; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}