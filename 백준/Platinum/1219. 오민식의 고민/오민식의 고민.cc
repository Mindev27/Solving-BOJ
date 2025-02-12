#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

const ll INF = 1e18;
ll N, st, ed, M;
vector<tuple<ll, ll, ll>> edges; // (시작, 끝, 드는 비용)
vector<ll> adj[55];
ll cost[55];
ll money[55];          // i번째 노드에 도달했을때 돈
bool inf[55];           // 무한대로 가는 놈들

void bellmanford(ll s) {
    fill(money, money + 55, -INF);
    fill(inf, inf + 55, false);

    // N - 1번 돌리고
    money[s] = cost[s];
    for (ll i = 0; i < N - 1; i++) {
        for (auto [from, to, w] : edges) {
            if (money[from] != -INF && money[to] < money[from] - w) {
                money[to] = money[from] - w;
            }
        }
    }

    // 마지막에 돌릴때 사이클이 생기는 to 노드를 모두 기록
    for (auto [from, to, w] : edges) {
        if (money[from] != -INF
            && money[to] < money[from] - w) {
            inf[to] = true;
        }
    }
}

bool BFS(ll x) {
    bool visited[55];
    queue<ll> q;
    fill(visited, visited + 55, false);

    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        if (cur == ed) return true;

        for (ll& nxt : adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push(nxt);
        }
    }
    return false;
}

void solve() {
    cin >> N >> st >> ed >> M;
    for (ll i = 0; i < M; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        adj[x].push_back(y);
        edges.push_back({ x, y, c });
    }

    for (ll i = 0; i < N; i++) {
        cin >> cost[i];
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            if (i == get<1>(edges[j])) {
                get<2>(edges[j]) -= cost[i];
            }
        }
    }


    bellmanford(st);

    // 일단 목표에 도달안되면 끗
    if (money[ed] == -INF) {
        cout << "gg";
        return;
    }

    // 무한대인 놈들에게서 ed로 도달 가능한가?
    bool flag = false;
    for (ll i = 0; i < N; i++) {
        if (inf[i]) {
            if (BFS(i)) {
                flag = true;
                break;
            }
        }
    }

    if (flag) cout << "Gee";
    else cout << money[ed] << '\n';

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