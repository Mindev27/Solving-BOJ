#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first 
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int g1, s1, b1, g2, s2, b2;

void solve() {
    cin >> g1 >> s1 >> b1;
    cin >> g2 >> s2 >> b2;

    if (g1 < g2 && s1 < s2 && b1 < b2) {
        cout << "-1";
        return;
    }

    int ans = 0;

    while (b1 < b2) { s1 -= 1; b1 += 9; ans++; }

    while (g1 < g2) { s1 -= 11; g1 += 1; ans++; }

    while (g1 >= g2 + 1 && s1 < s2) { g1 -= 1; s1 += 9; ans++; }

    while (b1 >= b2 + 11 && s1 < s2) { b1 -= 11; s1 += 1; ans++; }

    cout << (s1 >= s2 ? ans : -1) << '\n';
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
