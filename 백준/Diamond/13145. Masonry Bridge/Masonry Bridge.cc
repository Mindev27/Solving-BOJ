// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
https://algoshitpo.github.io/2020/03/23/dual/

듀얼그래프 공부 / 보고 풀었음

최솟값: 원본 그래프에서 1->N 다익스트라
최댓값: 듀얼 그래프에서 위/아래 면 분리 후 다익스트라
x=x1, x=xN 수직선으로 외부 face를 위/아래로 나눔
*/

const ll INFLL = (1LL<<62);
const int MAXN = 50000 + 10;
const int MAXM = 1000000 + 10;

int N, M, Mtot;
pll p[MAXN];
int uE[MAXM], vE[MAXM];
ll hE[MAXM];

vector<pll> g[MAXN];

int par[2*MAXM];

// 부모찾는 함수
int f(int x){
    int root = x;
    while(par[root] != root) root = par[root];
    while(par[x] != root){
        int nxt = par[x];
        par[x] = root;
        x = nxt;
    }
    return root;
}

// dsu union
void uni(int a,int b){
    a=f(a); b=f(b);
    if(a!=b) par[a]=b;
}

ll ccw(pll a, pll b, pll c){
    ll ax = c.X - b.X, ay = c.Y - b.Y;
    ll bx = c.X - a.X, by = c.Y - a.Y;
    __int128 d = (__int128)ax*by - (__int128)ay*bx;
    return (d>0)-(d<0);
}

// 현재 잡은 정점을 기준으로 시계방향으로 정렬해서 face를 union할거다
pll o;

// A B가 {edgeId, toVertex}라서 다음 정점이 될거임
bool cmpAng(pll A, pll B){
    pll a = p[A.Y], b = p[B.Y]; // a b는 각각 간선너머 정점
    if ((a>o) ^ (b>o)) return a > b; // 기준에 대해서 같은 방향인가
    return ccw(a, o, b) > 0; // 같으면 ccw로 정렬
}

// 일단 2*e+1을 기본값으로 방향 반대면 뒤집기임
// 오른쪽이거나 x같은데 아래이거나하면 뒤집어라
int pickHe(int v, int to, int e, int base){
    int he = base;
    if (p[to].X > p[v].X) he ^= 1;
    if (p[to].X == p[v].X && p[to].Y < p[v].Y) he ^= 1;
    return he;
}

int topFaceHe, bottomFaceHe;

// 한정점 v를 잡고 여기에 있는 모든 간선들을 정렬함.
// 이제 정렬된 정점들에 대해서 인접한거 두개잡고 face를 union하는과정
void buildFaces(){
    for(int i=0;i<2*Mtot;i++) par[i]=i;

    int totalV = N + 4; // N개 실제 + 4개 가상 정점
    for(int v=1;v<=totalV;v++){
        o = p[v];
        auto &adj = g[v];
        sort(adj.begin(), adj.end(), cmpAng);
        int d = adj.size();
        // degree-1 정점: 브릿지 간선의 양쪽 half-edge는 같은 face
        if(d == 1){
            int e1 = adj[0].X;
            uni(2*e1, 2*e1+1);
            continue;
        }
        if(d == 0) continue;
        for(int i=1;i<d;i++){
            int e1 = adj[i-1].X, t1 = adj[i-1].Y;
            int e2 = adj[i].X,   t2 = adj[i].Y;
            int h1 = pickHe(v,t1,e1,2*e1+1);
            int h2 = pickHe(v,t2,e2,2*e2);
            uni(h1,h2);
        }
        {
            int e1 = adj[d-1].X, t1 = adj[d-1].Y;
            int e2 = adj[0].X,   t2 = adj[0].Y;
            int h1 = pickHe(v,t1,e1,2*e1+1);
            int h2 = pickHe(v,t2,e2,2*e2);
            uni(h1,h2);
        }
    }

    // 위쪽 면: 상단 가로 가상간선(M+4)의 아래쪽 half-edge
    // 아래쪽 면: 하단 가로 가상간선(M+5)의 위쪽 half-edge
    // 상단 가로간선(M+4)의 아래쪽 half-edge가 위쪽 면
    // 하단 가로간선(M+5)의 위쪽 half-edge가 아래쪽 면
    topFaceHe = 2*(M+4)+1;
    bottomFaceHe = 2*(M+5);
}

unordered_map<int,int> faceId; // faceroot를 듀얼 그래프 정점으로 매핑
int numFaces;
int topId, bottomId; // 위/아래 외부 face의 압축된 정점번호
vector<vector<pair<int,ll>>> dualG; // 듀얼그래프 adj

void buildDual(){
    faceId.clear();
    numFaces = 0;

    // 루트를 정점번호로 압축
    // 루트정점들을 0,1,2...로 매핑하는거임
    auto getId = [&](int r) -> int {
        auto it = faceId.find(r);
        if(it!=faceId.end()) return it->Y;
        int id = numFaces++;
        faceId[r]=id;
        return id;
    };

    // 이제 이걸 map에 넣어서 매핑하기
    for(int i=0;i<2*Mtot;i++) getId(f(i));
    topId = faceId[f(topFaceHe)];
    bottomId = faceId[f(bottomFaceHe)];

    // 듀얼 인접리스트 구성 (실제 간선만, 가상 간선 제외)
    dualG.assign(numFaces, {});

    for(int i=0;i<M;i++){
        int A = faceId[f(2*i)];
        int B = faceId[f(2*i+1)];

        if(A==B) continue; // 두 번호가 같으면 같은 평면임

        dualG[A].push_back({B,hE[i]});
        dualG[B].push_back({A,hE[i]});
    }
}

// 듀얼 그래프에서 다익스트라
vector<ll> dijkstraDual(int src){
    vector<ll> dist(numFaces, INFLL);
    dist[src] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : dualG[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void solve() {
    cin >> N;

    for(int i=1;i<=N;i++){
        ll x,y; cin >> x >> y;
        p[i] = {x,y};
        g[i].clear();
    }

    cin >> M;

    ll totalSum = 0;
    for(int i=0;i<M;i++){
        int u,v; ll h;
        cin >> u >> v >> h;
        uE[i]=u; vE[i]=v; hE[i]=h;
        g[u].push_back({i,v});
        g[v].push_back({i,u});
        totalSum += h;
    }

    // 가상 정점 추가: x=x1, x=xN 수직선으로 외부 face를 위/아래로 분리
    ll BIG = 2000000001LL;
    p[N+1] = {p[1].X, BIG};    // 좌상
    p[N+2] = {p[N].X, BIG};    // 우상
    p[N+3] = {p[1].X, -BIG};   // 좌하
    p[N+4] = {p[N].X, -BIG};   // 우하
    for(int i=N+1;i<=N+4;i++) g[i].clear();

    // 가상 간선 추가
    int ve = M;
    auto addVirtual = [&](int u, int v){
        g[u].push_back({ve,v});
        g[v].push_back({ve,u});
        uE[ve]=u; vE[ve]=v; hE[ve]=0;
        ve++;
    };
    addVirtual(1, N+1);      // M+0: 좌측 수직 위
    addVirtual(1, N+3);      // M+1: 좌측 수직 아래
    addVirtual(N, N+2);      // M+2: 우측 수직 위
    addVirtual(N, N+4);      // M+3: 우측 수직 아래
    addVirtual(N+1, N+2);    // M+4: 상단 가로
    addVirtual(N+3, N+4);    // M+5: 하단 가로
    Mtot = ve;

    buildFaces();
    buildDual();

    // 듀얼 그래프에서 위/아래 면으로부터 다익스트라
    auto distTop = dijkstraDual(topId);
    auto distBot = dijkstraDual(bottomId);

    ll maxAns = 0;
    for(int i=0;i<M;i++){
        int A = faceId[f(2*i)];
        int B = faceId[f(2*i+1)];
        ll c1 = (distTop[A]<INFLL && distBot[B]<INFLL) ? distTop[A]+distBot[B] : INFLL;
        ll c2 = (distTop[B]<INFLL && distBot[A]<INFLL) ? distTop[B]+distBot[A] : INFLL;
        ll mc = min(c1, c2);
        if(mc < INFLL) maxAns = max(maxAns, totalSum - mc);
    }

    // 최솟값: 원본 그래프에서 1->N 다익스트라
    vector<ll> distOrig(N+1, INFLL);
    distOrig[1] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > distOrig[u]) continue;
        for(auto [ei, v] : g[u]){
            if(ei >= M || v > N) continue;
            ll w = hE[ei];
            if(distOrig[u] + w < distOrig[v]){
                distOrig[v] = distOrig[u] + w;
                pq.push({distOrig[v], v});
            }
        }
    }

    cout << distOrig[N] << " " << maxAns << "\n";
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