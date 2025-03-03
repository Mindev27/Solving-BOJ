#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, Q;

vector<set<int>> s;

void solve() {
    cin >> N >> Q;

    s.resize(N+1);
    for(int i = 1; i <= N; i++) {
        int x; cin >> x;
        while(x--) {
            int k; cin >> k;
            s[i].insert(k);
        }
    }

    while(Q--) {
        int cmd; cin >> cmd;
        if(cmd == 1) {
            int a, b; cin >> a >> b;
            if(s[a].size() < s[b].size()) {
                swap(s[a], s[b]);
            }

            for(auto &i : s[b]) {
                s[a].insert(i);
            }
            s[b].clear();
        }
        else {
            int a; cin >> a;
            cout << s[a].size() << '\n';
        }
    }
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
