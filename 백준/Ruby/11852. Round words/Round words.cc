// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long

/*

*/

int dp[4025][2015];
int from[4025][2015];

int cyclicLcs(const string &s, const string &t) {
    int n = s.size(), m = t.size();
    if(n == 0 || m == 0) return 0;
    auto eq = [&](int a, int b) {
        return s[(a - 1) % n] == t[(b - 1) % m];
    };

    for(int i = 0; i <= n * 2; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = 0;
            from[i][j] = 0;
            if(j && dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                from[i][j] = 0;
            }
            if(i && j && eq(i, j) && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                from[i][j] = 1;
            }
            if(i && dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                from[i][j] = 2;
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i + n][m] > ret) ret = dp[i + n][m];
        int x = i + 1, y = 0;
        while(y <= m && from[x][y] == 0) y++;
        for(; y <= m && x <= n * 2; x++) {
            from[x][y] = 0;
            dp[x][m]--;
            if(x == n * 2) break;
            for(; y <= m; y++) {
                if(from[x + 1][y] == 2) break;
                if(y + 1 <= m && from[x + 1][y + 1] == 1) {
                    y++;
                    break;
                }
            }
        }
    }
    return ret;
}

void solve() {
    string s, t;
    cin >> s >> t;
    string tr(t.rbegin(), t.rend());
    int a = cyclicLcs(s, t);
    int b = cyclicLcs(s, tr);
    cout << (a > b ? a : b) << '\n';
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
