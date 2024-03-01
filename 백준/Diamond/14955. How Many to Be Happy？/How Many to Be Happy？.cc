#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 105;

using namespace std;

// 간선 구조체
struct Edge {
  int to, c, f;
  Edge *dual;
  Edge() : Edge(-1, 0) {}
  Edge(int to1, int c1) : to(to1), c(c1), f(0), dual(nullptr) {}
  int spare() { return c - f; }
  void addFlow(int f1) {
    f += f1;
    dual->f -= f1;
  }
};

int N, M;
vector<Edge*> adj[MAX];
vector<pair<pii, int>> edges;

// 간선 만드는 함수
void makeEdge(int from, int to, int w) {
  Edge *e1 = new Edge(to, w), *e2 = new Edge(from, 0);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

// Edmond-Karp 알고리즘
int EdmondKarp(int S, int T) {
  int ans = 0;
  int prev[MAX];
  Edge *path[MAX];

  while(true) {
    fill(prev, prev + MAX, -1);
    queue<int> q;
    q.push(S); // 싱크에서 시작

    while(!q.empty() && prev[T] == -1) {
      int cur = q.front();
      q.pop();
      for(Edge *e : adj[cur]) {
        int next = e->to;

        // 용량이 남아있고, 방문하지 않았으면
        if(e->spare() > 0 && prev[next] == -1) {
          q.push(next);
          prev[next] = cur;
          path[next] = e;
          if(next == T) break; // 싱크 도착
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
      path[i]->addFlow(flow);
    }

    ans += flow;
  }
  return ans;
}

void input() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({{u, v}, w});
  }
}

void solve() {
  sort(edges.begin(), edges.end(),[](const pair<pii, int> &a, const pair<pii, int> &b) {
    return a.Y < b.Y;
  });

  int ans = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 1; j <= N; ++j)
      adj[j].clear();

    int s = edges[i].X.X, t = edges[i].X.Y;

    for (int j = 0; j < i; ++j) {
      if (edges[j].Y < edges[i].Y) {
        makeEdge(edges[j].X.X, edges[j].X.Y, 1);
        makeEdge(edges[j].X.Y, edges[j].X.X, 1);
      }
    }

    int result = EdmondKarp(s, t);
    ans += result;
  }

  cout << ans << '\n';
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