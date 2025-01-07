#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

string s;

void solve(int t) {
    cin >> s;
    int N = s.size();
    static bool dp[205][205][5]; // 0=Set, 1=Elist, 2=List, 3=Elem, 4=Atom
    memset(dp, false, sizeof(dp));

    // 빈 구간 -> Elementlist 가능
    for (int i = 0; i <= N; i++) dp[i][i - 1][1] = true;

    // 구간 길이 1부터 N까지
    for (int len = 1; len <= N; len++) {
        for (int l = 0; l + len - 1 < N; l++) {
            int r = l + len - 1;

            // Atom
            if (len == 1 && (s[l] == '{' || s[l] == '}' || s[l] == ',')) dp[l][r][4] = true;

            // Set
            if (len >= 2 && s[l] == '{' && s[r] == '}' && dp[l + 1][r - 1][1]) dp[l][r][0] = true;

            // Element
            if (dp[l][r][4] || dp[l][r][0]) dp[l][r][3] = true;

            // List
            if (dp[l][r][3]) dp[l][r][2] = true;
            for (int m = l; m + 1 < r && !dp[l][r][2]; m++) {
                if (dp[l][m][3] && s[m + 1] == ',' && dp[m + 2][r][2]) dp[l][r][2] = true;
            }

            // Elementlist
            if (dp[l][r][2]) dp[l][r][1] = true;
        }
    }
    cout << "Word #" << t << ": " << (dp[0][N - 1][0] ? "Set" : "No Set") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve(tt);
    }
    return 0;
}
