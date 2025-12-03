// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int INF = 0x3f3f3f3f;
const int MAX = 1005;

// 간선 구조체
struct Edge {
  int to, c, f, w;
  Edge *dual;
  Edge() : Edge(-1, 0, 0) {}
  Edge(int to1, int c1, int w1) : to(to1), c(c1), f(0), w(w1), dual(nullptr) {}
  int spare() { return c - f; }
  void addFlow(int f1) {
    f += f1;
    dual->f -= f1;
  }
};

int N, M, S = 0, T = MAX - 1;
vector<Edge*> adj[MAX];

// 간선 만드는 함수
void makeEdge(int from, int to, int c, int w) {

  Edge *e1 = new Edge(to, c, w), *e2 = new Edge(from, 0, -w);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

pii SPFA() {
  int totalCost = 0, totalFlow = 0;  

  while(true) {
    Edge *path[MAX];
    int prev[MAX], dist[MAX];
    bool inQ[MAX] = {};
    fill(prev, prev + MAX, -1);
    fill(dist, dist + MAX, INF);
    memset(inQ, false, sizeof(inQ));

    queue<int> q;
    q.push(S);
    dist[S] = 0;
    inQ[S] = true;

    while(!q.empty()) {
      int cur = q.front();
      q.pop();
      inQ[cur] = false;

      for(Edge *e : adj[cur]) {
        int next = e->to;
        if(e->spare() > 0 && dist[next] > dist[cur] + e->w) {
          dist[next] = dist[cur] + e->w;
          prev[next] = cur;
          path[next] = e;

          if(!inQ[next]){
            q.push(next);
            inQ[next] = true;
          }
        }
      }
    }

    // 싱크에 도달하지 못했으면 끝
    if(prev[T] == -1) break;

    // 최대유량을 찾고 각 간선에 흘러보내기
    int flow = INF;
    for(int i = T; i != S; i = prev[i]) {
      flow = min(flow, path[i]->spare());
    }
    for(int i = T; i != S; i = prev[i]) {
      totalCost += flow * path[i]->w;
      path[i]->addFlow(flow);
    }
    totalFlow += flow;
  }

  return {totalFlow, totalCost};
}

void solve() {
    for (int i = 0; i < MAX; i++)
        adj[i].clear();

    int n, m;
    cin >> n >> m;

    // S = 0, T = MAX - 1
    int R = 1;
    int Q = 2 * n + 2;

    // S -> R
    makeEdge(S, R, 2, 0);

    for (int i = 1; i <= n; i++) {
        int vin = 2 * i;
        int vout = 2 * i + 1;

        // 시작에서 각 정점 in
        makeEdge(R, vin, 1, 0);

        // 정점 하나당 -1
        makeEdge(vin, vout, 1, -1);

        // 각 정점에서 끝 허브
        makeEdge(vout, Q, 1, 0);
    }

    // 끝 허브에서 T
    makeEdge(Q, T, 2, 0);

    // 원래 그래프의 간선들
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int aout = 2 * a + 1;
        int bin = 2 * b;
        makeEdge(aout, bin, INF, 0);
    }

    pii res = SPFA();
    int totalFlow = res.X;
    int totalCost = res.Y;

    cout << -totalCost << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}