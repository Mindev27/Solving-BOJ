// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long

string A, B;
short up[2][17005];
short dn[2][17005];

void calc(int l1, int r1, int l2, int r2) {
    if(l1 > r1) {
        for(int j = l2; j <= r2; j++) cout << "a " << B[j] << '\n';
        return;
    }
    if(l2 > r2) {
        for(int i = l1; i <= r1; i++) cout << "d " << A[i] << '\n';
        return;
    }
    if(l1 == r1) {
        int pos = -1;
        for(int j = l2; j <= r2; j++) if(B[j] == A[l1]) { pos = j; break; }
        if(pos >= 0) {
            for(int j = l2; j < pos; j++) cout << "a " << B[j] << '\n';
            cout << "c " << A[l1] << '\n';
            for(int j = pos + 1; j <= r2; j++) cout << "a " << B[j] << '\n';
        } else {
            cout << "m " << B[l2] << '\n';
            for(int j = l2 + 1; j <= r2; j++) cout << "a " << B[j] << '\n';
        }
        return;
    }

    int mid = (l1 + r1) / 2;
    int m = r2 - l2 + 1;

    for(int j = 0; j <= m; j++) up[0][j] = j;
    for(int i = l1; i <= mid; i++) {
        int cur = (i - l1 + 1) & 1;
        int pre = cur ^ 1;
        up[cur][0] = i - l1 + 1;
        for(int j = 1; j <= m; j++) {
            short v;
            if(A[i] == B[l2 + j - 1]) v = up[pre][j - 1];
            else v = up[pre][j - 1] + 1;
            short d = up[pre][j] + 1;
            short a = up[cur][j - 1] + 1;
            if(d < v) v = d;
            if(a < v) v = a;
            up[cur][j] = v;
        }
    }
    int upRow = (mid - l1 + 1) & 1;

    for(int j = 0; j <= m; j++) dn[0][j] = j;
    for(int i = r1; i >= mid + 1; i--) {
        int cur = (r1 - i + 1) & 1;
        int pre = cur ^ 1;
        dn[cur][0] = r1 - i + 1;
        for(int j = 1; j <= m; j++) {
            short v;
            if(A[i] == B[r2 - j + 1]) v = dn[pre][j - 1];
            else v = dn[pre][j - 1] + 1;
            short d = dn[pre][j] + 1;
            short a = dn[cur][j - 1] + 1;
            if(d < v) v = d;
            if(a < v) v = a;
            dn[cur][j] = v;
        }
    }
    int dnRow = (r1 - mid) & 1;

    int best = INT_MAX, cut = 0;
    for(int k = 0; k <= m; k++) {
        int v = up[upRow][k] + dn[dnRow][m - k];
        if(v < best) { best = v; cut = k; }
    }

    calc(l1, mid, l2, l2 + cut - 1);
    calc(mid + 1, r1, l2 + cut, r2);
}

void solve() {
    cin >> A >> B;
    calc(0, (int)A.size() - 1, 0, (int)B.size() - 1);
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
