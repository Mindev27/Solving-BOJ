#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 


ll N, p1, p2, M, S;

void solve() {
    cin >> N >> p1 >> p2 >> M >> S;

    ll dm1 = abs(p1 - M), dm2 = abs(p2 - M);
    ll sm1 = abs(p1 - S), sm2 = abs(p2 - S);
    ll ms = abs(M - S);

    bool isP1 = (dm1 & 1LL);
    bool isP2 = (dm2 & 1LL);

    ll ans = -1;
    if (!isP1 && !isP2) {
        cout << -1;
        return;
    }

    // (M < p1 < p2)
    if (M < p1 && p1 < p2) {
        if (S <= p1 && p1 < S);
        if (S <= p1 && p1 < p2) {
            if (isP1)
                ans = dm1 + ms;
            else if (isP2) {
                if (S == 1 || M == 1)
                    ans = -1;
                else if (S <= M)
                    ans = dm2 + ms + sm1 + 1;
                else
                    ans = dm2 + ms + dm1 + 1;
            }
        }
        else if (p1 < S && S < p2) {
            if (isP1)
                ans = dm1 + ms;
            else if (isP2) {
                if (M == 1)
                    ans = -1;
                else
                    ans = dm2 + ms + dm1 + 1;
            }
        }
        else { // S >= p2
            if (isP1) {
                if (S == N)
                    ans = -1;
                else
                    ans = dm1 + ms + sm2 + 1;
            }
            else if (isP2) {
                if (M == 1)
                    ans = -1;
                else
                    ans = dm2 + ms + dm1 + 1;
            }
        }
    }
    // (p1 < M < p2)
    else if (p1 < M && M < p2) {
        if (S <= p1 && p1 < p2) {
            if (isP1 && isP2) {
                if (dm1 < dm2)
                    ans = dm1 + ms;
                else {
                    if (S == 1)
                        ans = dm1 + ms;
                    else
                        ans = min(dm1 + ms, dm2 + ms + sm1 + 1);
                }
            }
            else if (isP1 && !isP2)
                ans = dm1 + ms;
            else if (!isP1 && isP2) {
                if (S == 1)
                    ans = -1;
                else
                    ans = dm2 + ms + sm1 + 1;
            }
        }
        else if (p1 < S && S < p2) {
            if (isP1 && isP2) {
                if (dm1 < dm2)
                    ans = dm1 + ms;
                else
                    ans = dm2 + ms;
            }
            else if (isP1 && !isP2)
                ans = dm1 + ms;
            else if (!isP1 && isP2)
                ans = dm2 + ms;
        }
        else { // S >= p2
            if (isP1 && isP2) {
                if (dm1 < dm2) {
                    if (S == N)
                        ans = dm2 + ms;
                    else
                        ans = min(dm1 + ms + sm2 + 1, dm2 + ms);
                }
                else
                    ans = dm2 + ms;
            }
            else if (isP1 && !isP2) {
                if (S == N)
                    ans = -1;
                else
                    ans = dm1 + ms + sm2 + 1;
            }
            else if (!isP1 && isP2)
                ans = dm2 + ms;
        }
    }
    // (p1 < p2 < M)
    else if (p1 < p2 && p2 < M) {
        if (S <= p1 && p1 < p2) {
            if (isP2) {
                if (S == 1)
                    ans = -1;
                else
                    ans = dm2 + ms + sm1 + 1;
            }
            else if (isP1) {
                if (M == N)
                    ans = -1;
                else
                    ans = dm1 + ms + dm2 + 1;
            }
        }
        else if (p1 < S && S < p2) {
            if (isP2)
                ans = dm2 + ms;
            else if (isP1) {
                if (M == N)
                    ans = -1;
                else
                    ans = dm2 + ms + dm1 + 1;
            }
        }
        else { // S >= p2
            if (isP2)
                ans = dm2 + ms;
            else if (isP1) {
                if (S == N || M == N)
                    ans = -1;
                else if (M <= S)
                    ans = dm1 + ms + sm2 + 1;
                else
                    ans = dm1 + ms + dm2 + 1;
            }
        }
    }

    cout << ans;
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