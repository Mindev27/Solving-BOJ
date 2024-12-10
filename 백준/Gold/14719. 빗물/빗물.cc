#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>


void solve(){
    int H, W;
    int h[505];
    cin >> H >> W;
    for(int i = 0; i < W; i++) {
        cin >> h[i];
    }

    int ans = 0;
    for(int i = 0; i < W; i++) {
        int lMax = -1, rMax = -1;
        for(int j = 0; j < i; j++) {
            lMax = max(lMax, h[j]);
        }
        for(int j = i + 1; j < W; j++) {
            rMax = max(rMax, h[j]);
        }

        if(lMax > h[i] && rMax > h[i]) {
            ans += min(lMax, rMax) - h[i];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}