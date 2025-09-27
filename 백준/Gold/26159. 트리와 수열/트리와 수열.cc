#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*
결국 트리라 경로는 단일패스고
그래프 모양은 똑같으니까 간선의사용횟수 * 가중치로 계산하면 O(N)으로 계산될거고

그럼 사용횟수 내림차순 가중치 오름차순으로 슥슥 곱하죠
그럼 사용횟수를 어캐구할까

간선 사용횟수는 간선이 a---b이면 a서브트리크기 * b서브트리크기

dfs로 O(N)으로 계산하면 될듯

*/

int N;
vector<int> g[100005];
vector<ll> c;
const ll MOD = 1e9+7;

void solve() {
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    c.resize(N-1);
    for (auto &i : c) cin >> i;

    vector<int> sz(N + 1, 0); // 서브트리 크기
    vector<ll> cnt; // 사용횟수

    auto dfs = [&](auto&& self, int v, int p) -> int {
        sz[v] = 1;
        for (int u : g[v]) if (u != p) {
            int s = self(self, u, v);
            cnt.push_back(1LL * s * (N - s));
            sz[v] += s;
        }
        return sz[v];
    };

    dfs(dfs, 1, 0);

    sort(cnt.begin(), cnt.end());
    sort(c.rbegin(), c.rend());

    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = (ans + (cnt[i] % MOD) * (c[i] % MOD)) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc=1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}