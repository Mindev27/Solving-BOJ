#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 0x3f3f3f3f;
const int MAX = 205;

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

// 서점: 1~M, 사람 : M+1~M+N, 소스: 0, 싱크 : MAX - 1 
void input() {
  int cap[105][105];
  cin >> N >> M;
  for(int i  = 1; i <= N; i++) {
    int x; cin >> x;
    makeEdge(i + M, T, x, 0);
  }
  for(int i = 1; i <= M; i++) {
    int x; cin >> x;
    makeEdge(S, i, x, 0);
  }
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N; j++)
      cin >> cap[i][j];

  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= N; j++) {
      int cost; cin >> cost;
      makeEdge(i, j + M, cap[i][j], cost);
    }
  }
}

void solve() {

  pii ans = SPFA();
  cout << ans.X << '\n' << ans.Y;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}