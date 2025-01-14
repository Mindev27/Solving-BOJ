#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N;
int mat[405][405];
int diag1[405][405];    // 주대각선 누적합
int diag2[405][405];    // 다른 대각선 누적합

int score(int k, int x, int y) {
    int ex = x + k - 1, ey = y + k - 1;

    int A = diag1[ex][ey];
    if (x > 1 && y > 1) A -= diag1[x - 1][y - 1];

    int B = diag2[ex][y];
    if (x > 1 && ey < N) B -= diag2[x - 1][ey + 1];

    return A - B;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> mat[i][j];
            diag1[i][j] = mat[i][j] + diag1[i - 1][j - 1];
            diag2[i][j] = mat[i][j] + diag2[i - 1][j + 1];
        }
    }

    int ans = INT_MIN;


    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N - k + 1; i++) {
            for (int j = 1; j <= N - k + 1; j++) {
                ans = max(ans, score(k, i, j));
            }
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
    for (int tt = 1;tt <= Tc;tt++) {
        solve();
    }

    return 0;
}
