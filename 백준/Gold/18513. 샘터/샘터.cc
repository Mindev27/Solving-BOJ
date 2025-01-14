#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, K;
queue<pair<ll, int>> q;
unordered_set<ll> visited;


void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        q.push({ x, 0 });
        visited.insert(x);
    }

    ll ans = 0;
    int cnt = 0;
    while (!q.empty()) {
        ll x = q.front().X;
        int d = q.front().Y;
        q.pop();

        ll nx;

        // 앞
        nx = x - 1;
        if (visited.find(nx) == visited.end()) {
            visited.insert(nx);
            q.push({ nx, d + 1 });
            ans += d + 1;
            if (cnt + 1 == K) break;
            else cnt++;
        }

        // 뒤
        nx = x + 1;
        if (visited.find(nx) == visited.end()) {
            visited.insert(nx);
            q.push({ nx, d + 1 });
            ans += d + 1;
            if (cnt + 1 == K) break;
            else cnt++;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1;tt <= Tc;tt++) {
        solve();
    }

    return 0;
}
