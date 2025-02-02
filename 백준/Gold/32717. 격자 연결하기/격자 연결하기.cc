#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first 
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, M;
int board[1005][1005];
int dr[1005][1005];
int ur[1005][1005];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    memset(dr, 0, sizeof(dr));
    memset(ur, 0, sizeof(ur));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dr[i][j] = max({ 0, dr[i - 1][j], dr[i][j - 1] }) + board[i][j];
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= M; j++) {
            ur[i][j] = max({ 0, ur[i + 1][j], ur[i][j - 1] }) + board[i][j];
        }
    }

    int ans = -99999999;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans = max({ ans, ur[i][j], dr[i][j] });
        }
    }

    cout << ans << '\n';
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
