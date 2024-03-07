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
const int MAX = 2010;

// 간선 구조체
struct Edge {
  int to, c, f, d;
  Edge *dual;
  Edge() : Edge(-1, 0, 0) {}
  Edge(int to1, int c1, int d1) : to(to1), c(c1), f(0), d(d1), dual(nullptr) {}
  int spare() { return c - f; }
  void addFlow(int f1) {
    f += f1;
    dual->f -= f1;
  }
};

int V, E, S, T;
vector<Edge*> adj[MAX];

// 간선 만드는 함수
void makeEdge(int from, int to, int w, int d) {
  Edge *e1 = new Edge(to, w, d), *e2 = new Edge(from, 0, -d);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

void init() {
  for(int i = 0; i < MAX; i++) {
    adj[i].clear();
  }
}

// 정점 쪼개기 i번째정점 -> in: i*2, out: i*2+1
void input() {
  for(int i = 2; i < V; i++) {
    int in = i * 2;
    int out = i * 2 + 1;
    makeEdge(in, out, 1, 0);
  }

  S = 1 * 2;     // 소스는 1의 in
  T = V * 2 + 1; // 싱크는 V의 out
  makeEdge(S, 1 * 2 + 1, 2, 0);
  makeEdge(V * 2, T, 2, 0);

  for(int i = 0; i < E; i++) {
    int a, b, c; cin >> a >> b >> c;
    makeEdge(a * 2 + 1, b * 2, 1, c);
  }
}

// Edmond-Karp 알고리즘
int EdmondKarp() {
  int result = 0;
  int prev[MAX];   // 이전에 방문한 정점 정보
  Edge *path[MAX]; // 이전으로 가기위한 간선 정보
  bool visited[MAX] = {};
  int dist[MAX] = {};
  
  
  
  while(true) {
    queue<int> q;
    fill(prev, prev + MAX, -1);
    memset(dist, INF, sizeof(dist));
    memset(visited, false, sizeof(visited));
    
    dist[S] = 0;
    q.push(S); // 싱크에서 시작

    while(!q.empty()) {
      int cur = q.front();
      q.pop();
      
      visited[cur] = false; // 더 나은길을 탐색하기 위함함
      
      for(Edge *e : adj[cur]) {
        int next = e->to;

        // 용량이 남아있고, 거리가 가까워진다면
        if(e->spare() > 0 && dist[cur] + e->d < dist[next]) {
          dist[next] = dist[cur] + e->d;
          prev[next] = cur;
          path[next] = e;
          if(!visited[next]) {
            q.push(next);
            visited[next] = true;
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
      path[i]->addFlow(flow);
      result += path[i]->d;
    }
  }

  return result;
}

void solve() {
  cout << EdmondKarp() << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(cin >> V >> E) {
    init();
    input();
    solve();
  }

  return 0;
}