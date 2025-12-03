// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int INF = 0x3f3f3f3f;
const int MAX = 3005;

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

int N, M, S, T;
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

// 2에서  1 N으로 가는 정정 분할 최소 비용 2유량
void solve() {
    cin >> N >> M;

    S = 0;
    T = N + 1;

    makeEdge(S, 2, 2, 0);

    makeEdge(1, T, 1, 0);
    makeEdge(N, T, 1, 0);

    for (int i = 0; i < M; i++) {
        int s, e, d;
        cin >> s >> e >> d;

        // 양방향
        makeEdge(s, e, 1, d);
        makeEdge(e, s, 1, d);
    }

    pii res = SPFA();
    int totalFlow = res.X;
    int totalCost = res.Y;
    
    cout << totalCost << '\n';
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