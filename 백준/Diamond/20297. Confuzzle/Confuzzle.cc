// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
아까는 같은 색이었고 이번에는 같은 숫자임
up[i] = {c, d}가 i에서 센트로이드까지 거리인데
S[x]는 정점 x에 대해서 가까운 흰색 정점을 나타냈었어
이번에는 어떻게 할까
*/

int n, m;

int sz[100005];         // 서브 트리의 크기
vector<int> g[100005];  // 인접 리스트
vector<pii> up[100005]; // (센트로이드 c, 거리 d)
vector<int> num;        // 각 정점의 숫자
int bestVal[100005]; // c 기준 x 값인 정점까지의 최소 dist
bool used[100005];
const int INF = 1e9;
int ans = INF;

// b가 부모고 부모 빼고 재귀적으로 서브트리 크기 구해짐
int getSize(int v, int b = -1) { // 서브 트리의 크기를 구하는 DFS
    sz[v] = 1;
    for (auto i : g[v]) if (i != b && !used[i]) {
        sz[v] += getSize(i, v);
    }
    return sz[v];
}

// 자식 노드가 아닌것들 중에서 전체(cap)의 절반이상이 되는 정점을 고르기
int getCent(int v, int b = -1, int cap = n) { // 센트로이드를 찾는 DFS
    for (auto i : g[v])
        if (i != b && !used[i] && sz[i] * 2 > cap)
            return getCent(i, v, cap);
    return v;
}

void collect(int v, int p, int dist, vector<pii> &nodes) {
    nodes.push_back({num[v], dist}); // (값, c에서의 거리)
    for (int nxt : g[v]) {
        if (nxt == p || used[nxt]) continue;
        collect(nxt, v, dist + 1, nodes);
    }
}

void build(int v) {
    int tot = getSize(v, -1);
    int c = getCent(v, -1, tot);

    used[c] = true;

    // 이번 센트로이드에서 접근한 value
    static vector<int> active;
    active.clear();

    // 센트로이드 자신
    int colC = num[c];
    bestVal[colC] = 0;
    active.push_back(colC);

    for (int nxt : g[c]) {
        if (used[nxt]) continue;

        vector<pii> nodes; // (값, dist(c, v))
        collect(nxt, c, 1, nodes);

        for (auto &p : nodes) {
            int val = p.X;
            int d = p.Y;
            if (bestVal[val] != INF) {
                ans = min(ans, bestVal[val] + d);
            }
        }

        for (auto &p : nodes) {
            int val = p.X;
            int d = p.Y;
            if (bestVal[val] > d) {
                if (bestVal[val] == INF) active.push_back(val);
                bestVal[val] = d;
            }
        }
    }

    for (int i : active) bestVal[i] = INF;

    for (int nxt : g[c]) {
        if (used[nxt]) continue;
        build(nxt);
    }
}

void solve() {
    cin >> n;
    num.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> num[i];

    for (int i = 1; i <= n; i++) {
        g[i].clear();
        used[i] = false;
        bestVal[i] = INF;
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    build(1);

    cout << ans << '\n';
    
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
