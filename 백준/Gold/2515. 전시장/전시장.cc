#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
걍 보자마자 DP스멜
dp[i] = 높이가 H[i]인 그림을 마지막으로 선택했을 때 얻을 수 있는 최대 가격 합

dp[i] = (그림 i가격) + (이전까지 고른 그림 중 높이가 H[i]-S 이하인 그림들 중에서의 최대이익)
*/

const ll INF = 1e18;
ll N, S;
vector<pll> pic;

void solve() {
    cin >> N >> S;
    pic.resize(N+1);
    for(int i = 1; i <= N; i++) {
        ll H, C; cin >> H >> C;
        pic[i] = {H,C};
    }

    sort(pic.begin()+1, pic.end());

    vector<ll> H(N+1), C(N+1), dp(N+1);
    for (int i = 1; i <= N; i++) {
        H[i] = pic[i].X;
        C[i] = pic[i].Y;
    }

    

    ll best = 0;
    int p = 1;
    ll ans = 0;

    for (int i = 1; i <= N; i++) {
        while (p <= N && H[p] <= H[i] - S) {
            best = max(best, dp[p]);
            p++;
        }

        if (H[i] < S)  dp[i] = -INF;
        else {
            dp[i] = C[i] + max(0LL, best);
            ans = max(ans, dp[i]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc=1;
    //cin >> Tc;
    while (Tc--) solve();

    return 0;
}