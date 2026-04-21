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
short up[2][15005];
short dn[2][15005];
string lcsResult;

void hirsch(int l1, int r1, int l2, int r2) {
    if(l1 > r1 || l2 > r2) return;
    if(l1 == r1) {
        for(int j = l2; j <= r2; j++) if(B[j] == A[l1]) { lcsResult.push_back(A[l1]); return; }
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

    hirsch(l1, mid, l2, l2 + cut - 1);
    hirsch(mid + 1, r1, l2 + cut, r2);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    A = s;
    B = string(s.rbegin(), s.rend());
    hirsch(0, n - 1, 0, n - 1);

    int K = lcsResult.size();
    cout << n - K << '\n';

    int l = 0, r = n - 1;
    string pre, suf;
    int half = K / 2;
    for(int k = 0; k < half; k++) {
        char c = lcsResult[k];
        while(l <= r && s[l] != c) { pre.push_back(s[l]); suf.push_back(s[l]); l++; }
        while(l <= r && s[r] != c) { pre.push_back(s[r]); suf.push_back(s[r]); r--; }
        pre.push_back(c);
        suf.push_back(c);
        l++; r--;
    }
    string mid;
    if(K & 1) {
        char c = lcsResult[half];
        while(l <= r && s[l] != c) { pre.push_back(s[l]); suf.push_back(s[l]); l++; }
        while(l <= r && s[r] != c) { pre.push_back(s[r]); suf.push_back(s[r]); r--; }
        mid.push_back(c);
        l++; r--;
    }
    while(l <= r) { pre.push_back(s[l]); suf.push_back(s[l]); l++; }
    reverse(suf.begin(), suf.end());
    cout << pre << mid << suf << '\n';
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
