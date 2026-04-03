// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
dp[i][j] := i번째 정점에 대해서 값이 j일때 서브트리 비용의 최솟값

점화식
dp[i][j] = j + i의 모든 자식정점 u에 대해서 allsum(k != j 인 dp[u][k])


*/

const ll INF = 0x3f3f3f3f3f3f3f3f;
int N;
vector<int> adj[100005];
ll dp[100005][20];

void dfs(int cur, int p) {
    for(int &nxt : adj[cur]) {
        if(nxt == p) continue;
        dfs(nxt, cur);
    }

    for(int j = 1; j < 20; j++) {
        dp[cur][j] = j;
        for(int &nxt : adj[cur]) {
            if(nxt == p) continue;

            ll curMin = INF;
            // 자식들에 대해서 먼저 모든 k값중 최솟값을 다 찾아야함
            for(int k = 1; k < 20; k++) {
                if(k == j) continue;
                curMin = min(curMin, dp[nxt][k]);
            }

            dp[cur][j] += curMin;
        }
    }
}

void solve() {
    cin >> N;

    for(int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    ll ans = INF;
    for(int i = 1; i < 20 ; i++) {
        ans = min(ans, dp[1][i]);
    }

    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}