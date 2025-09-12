#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

// v[i][2] := i번째의 오른쪽 극 / v[i][6] := i번째의 왼쪽 극
int T; 
vector<string> v;

void solve() {
    cin >> T;
    v.resize(T);

    for(string &s : v) cin >> s;

    auto rotCW = [&](string &s) { // 시계
        s = s.back() + s;
        s.pop_back();
    };
    auto rotCCW = [&](string &s) { // 반시계
        s = s.substr(1) + s[0];
    };

    int K; cin >> K;
    while(K--) {
        int n, d; 
        cin >> n >> d;
        n--;

        vector<int> dir(T, 0);
        dir[n] = d;

        // 왼쪽 전파
        for (int i = n - 1; i >= 0; i--) {
            if (v[i][2] != v[i + 1][6]) dir[i] = -dir[i + 1];
            else break;
        }
        // 오른쪽 전파
        for (int i = n + 1; i < T; i++) {
            if (v[i - 1][2] != v[i][6]) dir[i] = -dir[i - 1];
            else break;
        }

        // 회전
        for (int i = 0; i < T; i++) {
            if (dir[i] == 1) rotCW(v[i]);
            else if (dir[i] == -1) rotCCW(v[i]);
        }
    }

    int ans = 0;
    for(string &s : v) {
        if(s[0] == '1') ans++;
    }

    cout << ans << '\n';
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
