#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N = 0;
map<string, int> mp;

void solve() {
    string s;
    while(cin >> s) {
        if(s == "-") break;
        N++;
        mp.insert({s, 1});
    }

    while(cin >> s) {
        if(s =="#") break;

        int pcnt[26] = {0};
        for (char c : s) pcnt[c - 'A']++;

        int centerCnt[26] = {};

        for (auto it = mp.begin(); it != mp.end(); it++) {
            const string &w = it->first;

            int wcnt[26] = {};
            for (char c : w) wcnt[c - 'A']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (wcnt[i] > pcnt[i]) { ok = false; break; }
            }
            if (!ok) continue;

            for (int i = 0; i < 26; i++) {
                if (wcnt[i] > 0) centerCnt[i]++;
            }
        }

        int mn = INT_MAX, mx = -1;
        for (int i = 0; i < 26; i++) if (pcnt[i] > 0) {
            mn = min(mn, centerCnt[i]);
            mx = max(mx, centerCnt[i]);
        }

        for (int i = 0; i < 26; i++) {
            if (pcnt[i] > 0 && centerCnt[i] == mn) {
            cout << char('A' + i);
            }
        }
        cout << ' ' << mn << ' ';
        
        for (int i = 0; i < 26; i++) {
            if (pcnt[i] > 0 && centerCnt[i] == mx) {
            cout << char('A' + i);
            }
        }
        cout << ' ' << mx << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}
