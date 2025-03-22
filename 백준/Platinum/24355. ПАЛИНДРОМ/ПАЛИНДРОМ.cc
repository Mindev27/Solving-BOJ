#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

string S;

void solve() {
    cin >> S;
    reverse(S.begin(), S.end());
    string revS = S;
    reverse(revS.begin(), revS.end());
    if (S == revS) {
        cout << S.size();
        return;
    }

    string R = S;
    reverse(R.begin(), R.end());

    string T = R + "#" + S;
    int n = T.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && T[i] != T[j]) j = pi[j - 1];
        if (T[i] == T[j]) j++;
        pi[i] = j;
    }

    int L = pi[n - 1];

    string add = S.substr(0, S.size() - L);
    reverse(add.begin(), add.end());

    cout << S.size() + add.size();
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