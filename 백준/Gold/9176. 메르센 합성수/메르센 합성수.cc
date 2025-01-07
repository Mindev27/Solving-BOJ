#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int K;
int mp[] = { 11, 23, 29, 37, 41, 43, 47, 53, 59 }; // 메르센 합성수인 수수
string ans[] = {
    "23 * 89 = 2047 = ( 2 ^ 11 ) - 1",
    "47 * 178481 = 8388607 = ( 2 ^ 23 ) - 1",
    "233 * 1103 * 2089 = 536870911 = ( 2 ^ 29 ) - 1",
    "223 * 616318177 = 137438953471 = ( 2 ^ 37 ) - 1",
    "13367 * 164511353 = 2199023255551 = ( 2 ^ 41 ) - 1",
    "431 * 9719 * 2099863 = 8796093022207 = ( 2 ^ 43 ) - 1",
    "2351 * 4513 * 13264529 = 140737488355327 = ( 2 ^ 47 ) - 1",
    "6361 * 69431 * 20394401 = 9007199254740991 = ( 2 ^ 53 ) - 1",
    "179951 * 3203431780337 = 576460752303423487 = ( 2 ^ 59 ) - 1",
};

// void primeFactorization(ll n) {
//     vector<pair<ll, int>> factors;

//     int count = 0;
//     while (n % 2 == 0) {
//         n /= 2;
//         count++;
//     }
//     if (count > 0) factors.push_back({ 2, count });

//     for (ll i = 3; i <= sqrt(n); i += 2) {
//         count = 0;
//         while (n % i == 0) {
//             n /= i;
//             count++;
//         }
//         if (count > 0) factors.push_back({ i, count });
//     }


//     if (n > 1) {
//         factors.push_back({ n, 1 });
//     }

//     for (const auto& factor : factors) {
//         cout << factor.first << "^" << factor.second << " ";
//     }
//     cout << endl;
// }


void solve() {
    // 전처리
    // for (int i = 0; i < 9; i++) {
    //     ll cur = (1 << mp[i]) - 1;
    //     cout << cur << '\n';
    //     primeFactorization(cur);
    // }

    cin >> K;
    for (int i = 0; i < 9; i++) {
        if (mp[i] <= K) {
            cout << ans[i] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) {
        solve();
    }
    return 0;
}
