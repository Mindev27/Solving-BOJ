#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

// dp[k][x] := k번 막을 수 있고 x만큼 보급량이 남았을때 최소금액
ll dp[305][10005];
ll X, K, C;
    
void solve() {
    cin >> X >> K >> C;

    for (int k = 0; k <= K; k++) {
        dp[k][0] = 0;
    }

    for (int x = 1; x <= X; x++) {
        dp[0][x] = x + C;
    }

    for (int k = 1; k <= K; k++) {
        for (int x = 1; x <= X; x++) {
            
            int lo = 1, hi = x;
            ll best = LLONG_MAX;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                // 성공하면 x-mid 남음
                ll costOk = dp[k][x - mid];
                // 차단되면 횟수 - 1
                ll costNo = dp[k - 1][x];
                ll can = mid + C + max(costOk, costNo);
                best = min(best, can);


                if (costOk < costNo)  hi = mid - 1;
                else lo = mid + 1;
            }

            dp[k][x] = best;
        }
    }
    
    cout << dp[K][X] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
