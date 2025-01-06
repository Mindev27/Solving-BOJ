#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N;
int board[5005][5005];
int sum[5005][5005];

void preCalc() {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + board[i][j];
        }
    }
}

inline int GetSum(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    preCalc();

    int Q; cin >> Q;
    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int outVal = GetSum(r1, c1, r2, c2);
        int inVal = GetSum(r1 + 1, c1 + 1, r2 - 1, c2 - 1);

        cout << inVal * 2 - outVal << '\n';
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
