#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N;
string s;

void solve() {
    cin >> N >> s;
    if (s[0] == '<' && s[(int)s.size() - 1] == '>') {
        int x = 1;
        for (int i = 1; i < N; i++) {
            if (s[i] == '<') x++;
            else break;
        }

        int y = 1;
        for (int i = N - 2; i >= 0; i--) {
            if (s[i] == '>') y++;
            else break;
        }

        cout << max(N - x, N - y);
    }
    else {
        cout << N;
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
