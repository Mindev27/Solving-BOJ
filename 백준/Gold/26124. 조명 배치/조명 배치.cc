#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int N, M;
int board[1005][1005];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == -1) continue;

            bool canBulb = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni < 0 || ni >= N || nj < 0 || nj >= M)
                    continue;

                if (board[ni][nj] == -1) continue;

                if (abs(board[i][j] - board[ni][nj]) > 1) {
                    cout << "-1";
                    return;
                }
                if (board[i][j] + 1 == board[ni][nj]) {
                    canBulb = false;
                    break;
                }
            }

            if (canBulb && board[i][j] != 0) ans++;
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
