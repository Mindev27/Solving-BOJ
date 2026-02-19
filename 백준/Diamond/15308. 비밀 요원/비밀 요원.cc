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
*/

const ll INFLL = (1LL<<62);
const int MAXN = 200000 + 5;
const int MAXM = 200000 + 105;

int N, M;
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

int outerRoot;

// 한정점 v를 잡고 여기에 있는 모든 간선들을 정렬함.
// 이제 정렬된 정점들에 대해서 인접한거 두개잡고 face를 union하는과정
void buildFaces(){
    for(int i=0;i<2*M;i++) par[i]=i;

    for(int v=1;v<=N;v++){
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

    // 외부 face를 잡는 부분 v를 가장 왼쪽 아래점으로 잡을거임
    int v = 1;
    for(int i=2;i<=N;i++) if(p[i] < p[v]) v=i;

    // 그 극점에서도 마찬가지로 각도정렬을 한다
    // 이점에서 0번째면 최대한 왼쪽 아래임 근데 여기 간선이 없겠지
    // 왜냐? 우리가 가장 왼쪽 아래점을 잡았잖아
    // 그러면 이제 시계방향으로 돌리면서 있는거 찾아보면 바깥으로 열린곳이겠지
    // 그러면 이제 바깥을 정의할 수 있는거임
    o = p[v];
    auto &adj = g[v];
    sort(adj.begin(), adj.end(), cmpAng);
    int e = adj[0].X, to = adj[0].Y;
    outerRoot = f(pickHe(v,to,e,2*e));  
}

vector<int> faceRoots; // dsu root로 구성된 듀얼정점을 저장
unordered_map<int,int> faceId; // faceroot를 듀얼 그래프 정점으로 매핑
vector<pair<int,ll>> dualG[205]; // 듀얼그래프 adj
int outerId; // 외부 face의 압축된 정점번호



void buildDual(){
    faceRoots.clear();
    faceId.clear();

    // 루트를 정점번호로 압축
    // 루트정점들을 0,1,2...로 매핑하는거임
    auto getId = [&](int r){
        auto it = faceId.find(r);
        if(it!=faceId.end()) return it->Y;
        int id = faceRoots.size();
        faceRoots.push_back(r);
        faceId[r]=id;
        return id;
    };

    // 이제 이걸 map에 넣어서 매핑하기
    for(int i=0;i<2*M;i++) getId(f(i));
    outerId = faceId[f(outerRoot)];

    // 듀얼 인접리스트 구성
    int F = faceRoots.size();
    for(int i=0;i<F;i++) dualG[i].clear();

    for(int i=0;i<M;i++){
        int A = faceId[f(2*i)];
        int B = faceId[f(2*i+1)];

        if(A==B) continue; // 두 번호가 같으면 같은 평면임

        dualG[A].push_back({B,hE[i]});
        dualG[B].push_back({A,hE[i]});
    }
}

// 현재 x = nx 에서, 위로 수직선을 쐈을 때
// 어떤 성벽이 가장 먼저 맞는지를 빠르게 찾기 위한 자료구조
ll nx_2; // 실제 x좌표의 2배 (0.5 오프셋을 정수로 처리)

// y = py + (qy-py)*(x-px)/(qx-px) 직선을 정수로 비교
struct Line{
    ll px, py, qx, qy; // 정규화된 두 끝점 (P < Q)
    int ei;             // 간선번호

    Line(){}

    // 정규화 같은 두선분을 만들때 항상 동일한 직선좌표를 얻기위함
    Line(pll P, pll Q, int id){
        if(P>Q) swap(P,Q);
        px=P.X; py=P.Y; qx=Q.X; qy=Q.Y;
        ei=id;
    }

    // 아래에 있는 선분이 먼저온다
    // x = nx_2/2 에서의 y값을 __int128 교차곱으로 비교
    bool operator<(Line const& o) const{
        __int128 d1 = 2*(qx-px), d2 = 2*(o.qx-o.px);
        __int128 v1 = (__int128)py*d1 + (__int128)(qy-py)*(nx_2-2*px);
        __int128 v2 = (__int128)o.py*d2 + (__int128)(o.qy-o.py)*(nx_2-2*o.px);
        __int128 L = v1*d2, R = v2*d1;
        if(L!=R) return L<R;
        return ei<o.ei;
    }
};

// 현재 x=nx에서 수직선과 교차하는 모든 성벽들이 들어 있음
// 항상 y순으로 정렬됨
// x가 변할 때마다, 어떤 성벽은 set에 들어오고 어떤 성벽은 나간다
set<Line> st;
bool usedEdge[MAXM];

// 점 (qx, qy)가 어느 face(면) 안에 있는지, 듀얼 정점 번호로 반환
int queryFace(ll qx, ll qy){
    nx_2 = 2*qx;
    Line key;
    key.px = 0; key.py = qy; key.qx = 1; key.qy = qy;
    key.ei = -1;
    auto it = st.lower_bound(key);  // key보다 위에 있는 첫 Line
    if(it==st.end()) return outerId;
    return faceId[f(2*(it->ei)+1)];
}

ll distF[205][205];
int regQ[MAXN];

// 이제 스위핑처럼 x에 대해서 현재 y에 놓여있는 간선들의 정보를 업데이트해줌
void handleVertex(int v){
    nx_2 = 2*p[v].X - 1;
    for(auto [ei,to] : g[v]){
        if(p[v].X == p[to].X) continue;
        if(!usedEdge[ei]) continue;
        auto it = st.lower_bound(Line(p[v], p[to], ei));
        if(it != st.end() && it->ei == ei){
            st.erase(it);
        }
    }
    nx_2 = 2*p[v].X + 1;
    for(auto [ei,to] : g[v]){
        if(p[v].X == p[to].X) continue;
        if(usedEdge[ei]) continue;
        st.insert(Line(p[v], p[to], ei));
        usedEdge[ei]=1;
    }
}

void solve() {
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        ll x,y; cin >> x >> y;
        p[i] = {x,y};
        g[i].clear();
    }

    for(int i=0;i<M;i++){
        int u,v; ll h;
        cin >> u >> v >> h;
        uE[i]=u; vE[i]=v; hE[i]=h;
        g[u].push_back({i,v});
        g[v].push_back({i,u});
        usedEdge[i]=0;
    }

    if(M==0){
        int Q; cin >> Q;
        for(int i=0;i<Q;i++){ ll a,b; cin>>a>>b; cout<<0<<"\n"; }
        return;
    }

    st.clear();

    buildFaces();
    buildDual();

    int F = faceRoots.size();
    
    for(int i=0;i<F;i++){
        for(int j=0;j<F;j++) distF[i][j] = (i==j?0:INFLL);
    }
    for(int i=0;i<F;i++){
        for(auto [to,w] : dualG[i]){
            distF[i][to] = min(distF[i][to], w);
        }
    }
    for(int k=0;k<F;k++){
        for(int i=0;i<F;i++){
            if(distF[i][k]==INFLL) continue;
            for(int j=0;j<F;j++){
                ll nk = distF[i][k] + distF[k][j];
                if(nk < distF[i][j]) distF[i][j]=nk;
            }
        }
    }

    int Q; cin >> Q;

    vector<pair<pll,int>> ev;

    for(int i=1;i<=N;i++){
        ev.push_back({p[i], i});      // 정점 이벤트는 +i
    }
    for(int i=1;i<=Q;i++){
        ll a,b; cin >> a >> b;
        ev.push_back({{a,b}, -i});    // 질의 이벤트는 -i
    }

    sort(ev.begin(), ev.end());

    for(auto &t : ev){
        ll x = t.X.X;
        int id = t.Y;
        if(id > 0){
            handleVertex(id);
        }else{
            int qi = -id;
            regQ[qi] = queryFace(t.X.X, t.X.Y);
        }
    }

    regQ[0] = outerId;
    for(int i=1;i<=Q;i++){
        cout << distF[regQ[i-1]][regQ[i]] << '\n';
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