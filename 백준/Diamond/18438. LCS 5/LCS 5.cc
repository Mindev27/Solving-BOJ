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

const int MAXM = 7005;
string A, B;
short up[2][MAXM];
short dn[2][MAXM];
string ans;

void lcs(int l1, int r1, int l2, int r2) {
    if(l1 > r1 || l2 > r2) return;
    if(l1 == r1) {
        for(int j = l2; j <= r2; j++) if(B[j] == A[l1]) { ans.push_back(A[l1]); return; }
        return;
    }
    int mid = (l1 + r1) / 2;
    int m = r2 - l2 + 1;

    for(int j = 0; j <= m; j++) up[0][j] = 0;
    for(int i = l1; i <= mid; i++) {
        int cur = (i - l1 + 1) & 1;
        int pre = cur ^ 1;
        up[cur][0] = 0;
        for(int j = 1; j <= m; j++) {
            if(A[i] == B[l2 + j - 1]) up[cur][j] = up[pre][j - 1] + 1;
            else up[cur][j] = up[pre][j] > up[cur][j - 1] ? up[pre][j] : up[cur][j - 1];
        }
    }
    int upRow = (mid - l1 + 1) & 1;

    for(int j = 0; j <= m; j++) dn[0][j] = 0;
    for(int i = r1; i >= mid + 1; i--) {
        int cur = (r1 - i + 1) & 1;
        int pre = cur ^ 1;
        dn[cur][0] = 0;
        for(int j = 1; j <= m; j++) {
            if(A[i] == B[r2 - j + 1]) dn[cur][j] = dn[pre][j - 1] + 1;
            else dn[cur][j] = dn[pre][j] > dn[cur][j - 1] ? dn[pre][j] : dn[cur][j - 1];
        }
    }
    int dnRow = (r1 - mid) & 1;

    int best = -1, cut = 0;
    for(int k = 0; k <= m; k++) {
        int v = up[upRow][k] + dn[dnRow][m - k];
        if(v > best) { best = v; cut = k; }
    }

    lcs(l1, mid, l2, l2 + cut - 1);
    lcs(mid + 1, r1, l2 + cut, r2);
}

void solve() {
    cin >> A >> B;
    lcs(0, (int)A.size() - 1, 0, (int)B.size() - 1);
    cout << ans.size() << '\n' << ans << '\n';
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
