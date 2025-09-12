#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

bool visited[1000000];
vector<ll> x, h;
queue<pair<pll, ll>> q;

void solve() {
    ll N, S; cin >> N >> S;
    
    x.resize(N + 1);
    h.resize(N + 1);

    for(ll i = 1; i <= N; i++) cin >> x[i];
    for(ll i = 1; i <= N; i++) cin >> h[i];

    ll lp = S-1, rp = S+1; // 여기 방문할 차례
    
    q.push({{x[S] - h[S], x[S] + h[S]}, S});

    while(!q.empty()) {
        ll cL = q.front().X.X;
        ll cR = q.front().X.Y;
        ll idx = q.front().Y;
        q.pop();

        visited[idx] = true;

        // cout << cL << ' ' << cR << ' ' << idx << '\n';

        // 범위안에 방문가능한게 있는지 확인하고 넣기
        while(0 < lp && cL <= x[lp]) {
            q.push({{x[lp] - h[lp], x[lp] + h[lp]}, lp});
            lp--;
        }
        while(rp <= N && x[rp] <= cR) {
            q.push({{x[rp] - h[rp], x[rp] + h[rp]}, rp});
            rp++;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i]) cout << i << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}