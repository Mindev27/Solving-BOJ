// Writer : exzile_27
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

const int MAXN = 100005;
const int MAXM = 100005;

int N, M, Q;
ll Xv, Yv;
pll p[MAXN];
int uE[MAXM], vE[MAXM];
vector<pll> g[MAXN];

// half-edge face DSU
int par[2 * MAXM];

int hF(int x) {
    while (par[x] != x)
        x = par[x] = par[par[x]];
    return x;
}
void hU(int a, int b) {
    a = hF(a);
    b = hF(b);
    if (a != b)
        par[a] = b;
}

ll ccw(pll a, pll b, pll c) {
    ll ax = c.X - b.X, ay = c.Y - b.Y;
    ll bx = c.X - a.X, by = c.Y - a.Y;
    __int128 d = (__int128)ax * by - (__int128)ay * bx;
    return (d > 0) - (d < 0);
}

pll o;
bool cmpAng(pll A, pll B) {
    pll a = p[A.Y], b = p[B.Y];
    if ((a > o) ^ (b > o))
        return a > b;
    return ccw(a, o, b) > 0;
}

int pickHe(int v, int to, int e, int base) {
    int he = base;
    if (p[to].X > p[v].X)
        he ^= 1;
    if (p[to].X == p[v].X && p[to].Y < p[v].Y)
        he ^= 1;
    return he;
}

void buildFaces() {
    for (int i = 0; i < 2 * M; i++)
        par[i] = i;
    for (int v = 1; v <= N; v++) {
        o = p[v];
        sort(g[v].begin(), g[v].end(), cmpAng);
        int d = g[v].size();
        if (d == 0)
            continue;
        if (d == 1) {
            hU(2 * g[v][0].X, 2 * g[v][0].X + 1);
            continue;
        }
        for (int i = 1; i < d; i++) {
            int e1 = g[v][i - 1].X, t1 = g[v][i - 1].Y;
            int e2 = g[v][i].X, t2 = g[v][i].Y;
            hU(pickHe(v, t1, e1, 2 * e1 + 1), pickHe(v, t2, e2, 2 * e2));
        }
        {
            int e1 = g[v][d - 1].X, t1 = g[v][d - 1].Y;
            int e2 = g[v][0].X, t2 = g[v][0].Y;
            hU(pickHe(v, t1, e1, 2 * e1 + 1), pickHe(v, t2, e2, 2 * e2));
        }
    }
}

int faceOf[2 * MAXM];
int numFaces;

// 듀얼 DSU
int dP[2 * MAXM], dSz[2 * MAXM];
int dFind(int x) {
    while (dP[x] != x)
        x = dP[x] = dP[dP[x]];
    return x;
}
void dMerge(int a, int b) {
    a = dFind(a);
    b = dFind(b);
    if (a == b)
        return;
    if (dSz[a] < dSz[b])
        swap(a, b);
    dP[b] = a;
    dSz[a] += dSz[b];
}

// 프라이멀
set<int> adj[MAXN];
bool alive[MAXM];
int col[MAXN];
int nxtCol;
int vis[MAXN];

unordered_map<ll, int> edgeMap;
ll eKey(int a, int b) {
    if (a > b)
        swap(a, b);
    return (ll)a * 100001 + b;
}

void solve() {
    cin >> N >> M >> Q >> Xv >> Yv;
    for (int i = 1; i <= N; i++) {
        cin >> p[i].X >> p[i].Y;
        g[i].clear();
        adj[i].clear();
    }
    edgeMap.clear();

    for (int i = 0; i < M; i++) {
        cin >> uE[i] >> vE[i];
        g[uE[i]].push_back({i, vE[i]});
        g[vE[i]].push_back({i, uE[i]});
        adj[uE[i]].insert(vE[i]);
        adj[vE[i]].insert(uE[i]);
        edgeMap[eKey(uE[i], vE[i])] = i;
        alive[i] = true;
    }

    if (M > 0) {
        buildFaces();
        map<int, int> fm;
        numFaces = 0;
        for (int i = 0; i < 2 * M; i++) {
            int r = hF(i);
            if (!fm.count(r))
                fm[r] = numFaces++;
            faceOf[i] = fm[r];
        }
    }
    else
        numFaces = 0;

    for (int i = 0; i < numFaces; i++) {
        dP[i] = i;
        dSz[i] = 1;
    }

    nxtCol = 0;
    memset(col, -1, sizeof col);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= N; i++) {
        if (col[i] != -1)
            continue;
        queue<int> q;
        q.push(i);
        col[i] = nxtCol;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
                if (col[v] == -1) {
                    col[v] = nxtCol;
                    q.push(v);
                }
        }
        nxtCol++;
    }

    ll aCnt = 0;
    for (int qi = 0; qi < Q; qi++) {
        int type;
        ll u, v;
        cin >> type >> u >> v;
        u = (u - 1 + Xv * aCnt) % N + 1;
        v = (v - 1 + Yv * aCnt) % N + 1;

        if (type == 1) {
            if (u == v)
                continue;
            auto it = edgeMap.find(eKey(u, v));
            if (it == edgeMap.end() || !alive[it->second])
                continue;
            int ei = it->second;
            alive[ei] = false;
            adj[u].erase((int)v);
            adj[v].erase((int)u);

            int fA = dFind(faceOf[2 * ei]);
            int fB = dFind(faceOf[2 * ei + 1]);
            if (fA != fB) {
                dMerge(fA, fB);
            }
            else {
                // 분리됨 간선 단위 교대 BFS
                int newC = nxtCol++;
                queue<int> qu, qv;
                vector<int> su, sv;
                vis[u] = 1;
                qu.push(u);
                su.push_back(u);
                vis[v] = 2;
                qv.push(v);
                sv.push_back(v);

                int curU = -1, curV = -1;
                set<int>::iterator itU, itV;
                int smaller = -1;

                while (smaller < 0) {
                    // U측 간선 1개
                    while (true) {
                        if (curU < 0) {
                            if (qu.empty()) {
                                smaller = 0;
                                break;
                            }
                            curU = qu.front();
                            qu.pop();
                            itU = adj[curU].begin();
                        }
                        if (itU == adj[curU].end()) {
                            curU = -1;
                            continue;
                        }
                        int nb = *itU;
                        ++itU;
                        if (!vis[nb]) {
                            vis[nb] = 1;
                            qu.push(nb);
                            su.push_back(nb);
                        }
                        break;
                    }
                    if (smaller >= 0)
                        break;
                    // V측 간선 1개
                    while (true) {
                        if (curV < 0) {
                            if (qv.empty()) {
                                smaller = 1;
                                break;
                            }
                            curV = qv.front();
                            qv.pop();
                            itV = adj[curV].begin();
                        }
                        if (itV == adj[curV].end()) {
                            curV = -1;
                            continue;
                        }
                        int nb = *itV;
                        ++itV;
                        if (!vis[nb]) {
                            vis[nb] = 2;
                            qv.push(nb);
                            sv.push_back(nb);
                        }
                        break;
                    }
                }

                if (smaller == 0)
                    for (int x : su)
                        col[x] = newC;
                else
                    for (int x : sv)
                        col[x] = newC;
                for (int x : su)
                    vis[x] = 0;
                for (int x : sv)
                    vis[x] = 0;
            }
        }
        else {
            if (col[u] == col[v]) {
                cout << "A\n";
                aCnt++;
            }
            else
                cout << "D\n";
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