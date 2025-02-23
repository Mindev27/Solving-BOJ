#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = INT_MAX;
    for(int start = 0; start < n; start++){
        vector<int> dist(n, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while(!q.empty()){
            int cur = q.front(); 
            q.pop();

            for(int nxt: adj[cur]){
                if(dist[nxt] == -1){
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }

                else if(dist[nxt] >= dist[cur]){
                    ans = min(ans, dist[cur] + dist[nxt] + 1);
                }
            }
        }
    }
    
    if(ans == INT_MAX) cout << "impossible\n";
    else cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        cout << "Case " << tt << ": ";
        solve();
    }
    return 0;
}
