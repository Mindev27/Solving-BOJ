#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, M;
vector<int> adj[500005];
int color[500005]; // 색은 0과 1

void solve() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    fill(color, color + 500005, -1);

    queue<pii> q; // 정점, 색
    color[1] = 0;
    q.push({1, 0});

    while(!q.empty()) {
        auto [curN, curColor] = q.front();
        q.pop();

        for(auto &nxt : adj[curN]) {
            if(color[nxt] == -1) {
                color[nxt] = (curColor == 1 ? 0 : 1);
                q.push({nxt, color[nxt]});
            }
            else {
                if(color[nxt] == color[curN]) {
                    cout << "0";
                    return;
                }
            }
        }
    }

    int zero = 0, one = 0;
    for(int i = 1; i <= N; i++) {
        if(color[i] == 1) one++;
        else zero++;
    }

    cout << 2LL * one * zero << '\n';

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
