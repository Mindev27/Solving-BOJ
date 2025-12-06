// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

// https://justicehui.github.io/hard-algorithm/2020/08/25/centroid/
// centroid for education

int n, m;

int sz[100005];         // 서브 트리의 크기
vector<int> g[100005];  // 인접 리스트
vector<pii> up[100005]; // (센트로이드 c, 거리 d)
vector<int> color;      // 검은색 0, 흰색 1
multiset<int> S[100005];
bool used[100005];

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

// 이번레벨의 센트로이드에 대해서 전체를 dfs하면서 v에 대해 up[v] 생성
void dfs(int v, int p, int dist, int c) {
    up[v].push_back({c, dist});

    for (int nxt : g[v]) {
        if (nxt == p || used[nxt])
            continue;
        dfs(nxt, v, dist + 1, c);
    }
}

void build(int v) {
    int tot = getSize(v, -1);
    int c = getCent(v, -1, tot);

    used[c] = true;
    dfs(c, -1, 0, c);

    for (int nxt : g[c]) {
        if (used[nxt])
            continue;
        build(nxt);
    }
}

void solve() {
    cin >> n;
    color.assign(n + 1, 0); // 처음엔 다 검은색
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    build(1);
    // for(int i = 1; i <= n; i++) {
    //     cout << "i : " << i << "\n";
    //     for(auto [c,d] : up[i]) {
    //         cout << "(" << c << ", " << d << ")" << '\n';
    //     }
    // }

    cin >> m;
    while (m--) {
        int op, v;
        cin >> op >> v;
        if (op == 1) { // 토글
            // cout << "Color : " << op << ' ' << v << '\n';
            if (color[v] == 0) { // 검은색 -> 흰색
                color[v] = 1;
                // up을 순회하면서 (c,d)에 대해서 S[c]에 d집어넣기
                for (auto &[c, d] : up[v]) {
                    S[c].insert(d);
                    // cout << c << "에 " << d << " insert\n";
                }
            }
            else {
                color[v] = 0;
                for (auto &[c, d] : up[v]) {
                    S[c].erase(S[c].find(d)); // d 찾아서 지우기
                    // cout << c << "에 " << d << " erase\n";
                }
            }
        }
        else { // 질의
            // cout << "Q: " <<  op << ' ' << v << '\n';
            // 이때마다 현재 up으로 순회하면서
            // S[c].begin() 젤 작은거랑 현재 거리 d를 더한값중 최소 출력
            int minVal = 999999999;
            for (auto &[c, d] : up[v]) {
                if (S[c].empty())
                    continue;
                minVal = min(minVal, *S[c].begin() + d);
                // cout << "c: " << c << " d: " << d << " res : " <<
                // *S[c].begin() + d << '\n';
            }
            if (minVal == 999999999)
                cout << "-1\n";
            else cout << minVal << '\n';
        }
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
