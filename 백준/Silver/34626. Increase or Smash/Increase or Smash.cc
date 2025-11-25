#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N;
vector<int> v;
bool cnt[105] = {};

void solve() {
    cin >> N;
    v.resize(N);
    for(int &i : v) cin >> i;

    memset(cnt, false, sizeof(cnt));
    for(int &i : v) {
       cnt[i] = true;
    }

    int ans = 0;
    for(int i = 1; i <= 100; i++) {
        if(cnt[i]) ans++;
    }
    if(ans == 0) {
        cout << "0\n";
        return;
    }
    ans += ans - 1;
    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}