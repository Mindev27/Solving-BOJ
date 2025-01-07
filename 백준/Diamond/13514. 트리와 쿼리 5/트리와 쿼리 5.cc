#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N, M;
int subSz[200005];
bool visited[200005];
vector<vector<pii>> g(200005);
bool colorArr[200005];                  // 노드 색
multiset<int> stCent[200005];           // c에서 흰노드와 거리
int cPar[200005];                       // cPar[i] := i의 부모
vector<pair<int, int>> cdDist[200005];   // 분해하면서 만난 다른것과 거리 목록록

int get_size(int cur, int par) {
    subSz[cur] = 1;
    for (const auto& nxt : g[cur]) {
        int v = nxt.X;
        if (v == par || visited[v]) continue;
        subSz[cur] += get_size(v, cur);
    }
    return subSz[cur];
}

int get_cent(int cur, int par, int thr) {
    for (const auto& p : g[cur]) {
        int v = p.X;
        if (v == par || visited[v]) continue;
        if (subSz[v] > thr) return get_cent(v, cur, thr);
    }
    return cur;
}

void dfsDist(int c, int start, int par, int distVal) {
    cdDist[start].push_back({ c, distVal });
    for (auto& nx : g[start]) {
        int nv = nx.X;
        if (nv == par || visited[nv]) continue;
        dfsDist(c, nv, start, distVal + 1);
    }
}

int buildCentroid(int start) {
    int sz = get_size(start, -1);
    int c = get_cent(start, -1, sz / 2);

    visited[c] = true;
    dfsDist(c, c, -1, 0);

    for (auto& nx : g[c]) {
        int v = nx.X;
        if (visited[v]) continue;
        int subCent = buildCentroid(v);
        cPar[subCent] = c;
    }

    return c;
}

int getDist(int u, int v) {
    static unordered_map<int, int> mem;
    mem.clear();
    for (auto& p : cdDist[u]) {
        int c = p.X;
        int d = p.Y;
        mem[c] = d;
    }

    int ret = INT_MAX;
    for (auto& p : cdDist[v]) {
        int c = p.X;
        int d = p.Y;
        if (mem.find(c) != mem.end()) {
            int cand = mem[c] + d;
            if (cand < ret) ret = cand;
        }
    }
    return ret;
}

void updateColor(int v) {
    colorArr[v] = !colorArr[v];

    for (auto& p : cdDist[v]) {
        int c = p.X;        // 센트로이드
        int d = p.Y;        // dist(v,c)
        if (colorArr[v]) {
            stCent[c].insert(d); // 흰색으로 바뀌면 삽입
        }
        else {
            // 검정으로 바뀌면 제거
            auto it = stCent[c].find(d);
            if (it != stCent[c].end()) {
                stCent[c].erase(it);
            }
        }
    }
}

// 가장 가까운 흰색 찾기
int query(int v) {
    int ans = INT_MAX;
    bool isExist = false;

    for (auto& p : cdDist[v]) {
        int c = p.X;   // 센트로이드
        int dvc = p.Y; // dist(v, c)

        if (!stCent[c].empty()) {
            isExist = true;
            int cand = *(stCent[c].begin()) + dvc;
            if (cand < ans) ans = cand;
        }
    }

    if (!isExist) return -1;
    return ans;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        g[i].clear();
        colorArr[i] = false; // 검정
        stCent[i].clear();
        cdDist[i].clear();
        cPar[i] = i;
        visited[i] = false;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({ v,1 });
        g[v].push_back({ u,1 });
    }

    int rootC = buildCentroid(1);

    cin >> M;
    while (M--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            updateColor(v);
        }
        else if (t == 2) {
            int ans = query(v);
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) {
        solve();
    }
    return 0;
}
