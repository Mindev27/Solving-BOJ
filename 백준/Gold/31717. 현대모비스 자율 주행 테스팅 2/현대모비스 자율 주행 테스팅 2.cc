#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

const ll INF = 1e18;
ll M, K;
vector<ll> a;
typedef struct {
    ll uu, ud, du, dd;
}maps;

void solve() {
    cin >> M >> K;
    a.resize(K);
    for(ll &i : a) cin >> i;

    vector<maps> mp(M + 1);
    for(ll x = 1; x <= M; x++) {
        string board[2];
        cin >> board[0];
        cin >> board[1];

        ll len = board[0].size();

        // 위에서 시작
        vector<vector<ll>> dp(2, vector<ll>(len, INF));
        dp[0][0] = (board[0][0] == '.' ? 1 : INF);
        dp[1][0] = (board[1][0] == '.' ? min(dp[0][0] + 1, INF) : INF);

        for(ll j = 1; j < len; j++) {
            for(ll i = 0; i < 2; i++) {
                dp[i][j] = INF;

                if(board[i][j] == '#') continue;
                
                if(dp[i][j-1] != INF) dp[i][j] = dp[i][j-1] + 1;
                if(dp[(i+1)%2][j-1] != INF && board[(i+1)%2][j] != '#') 
                    dp[i][j] = min(dp[i][j], dp[(i+1)%2][j-1] + 2);
            }
        }

        mp[x].uu = dp[0][len-1];
        mp[x].ud = dp[1][len-1];

        // 아래에서 시작
        dp[1][0] = (board[1][0] == '.' ? 1 : INF);
        dp[0][0] = (board[0][0] == '.' ? min(dp[1][0] + 1, INF) : INF);

        for(ll j = 1; j < len; j++) {
            for(ll i = 0; i < 2; i++) {
                dp[i][j] = INF;

                if(board[i][j] == '#') continue;
                
                if(dp[i][j-1] != INF) dp[i][j] = dp[i][j-1] + 1;
                if(dp[(i+1)%2][j-1] != INF && board[(i+1)%2][j] != '#') 
                    dp[i][j] = min(dp[i][j], dp[(i+1)%2][j-1] + 2);
            }
        }

        mp[x].du = dp[0][len-1];
        mp[x].dd = dp[1][len-1];
    }

    // for(auto &i : mp) {
    //     cout << i.uu << ' ' << i.ud << ' ' << i.du << ' ' << i.dd << '\n';
    // }

    vector<vector<ll>> dp(2, vector<ll>(K, INF)); // i=0 : u, i=1 : d
    dp[0][0] = min(mp[a[0]].uu, mp[a[0]].du);
    dp[1][0] = min(mp[a[0]].ud, mp[a[0]].dd);

    for(ll j = 1; j < K; j++) {
        dp[0][j] = min({dp[0][j], dp[0][j-1] + mp[a[j]].uu, dp[1][j-1] + mp[a[j]].du});
        dp[1][j] = min({dp[1][j], dp[0][j-1] + mp[a[j]].ud, dp[1][j-1] + mp[a[j]].dd});
    }

    // for(int i = 0; i < 2; i++) {
    //     for(int j = 0; j < K; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    
    // }

    ll ans = min(dp[0][K-1], dp[1][K-1]);
    cout << (ans != INF ? ans - 1 : -1);
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
