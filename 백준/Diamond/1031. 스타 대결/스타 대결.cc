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

using namespace std;

const int MAX = 105;

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

int N, M, S = 0, T = MAX - 1;
int sumA = 0, sumB = 0;
vector<Edge *> adj[MAX];

// 간선 만드는 함수
void makeEdge(int from, int to, int w) {
  Edge *e1 = new Edge(to, w), *e2 = new Edge(from, 0);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

// 소스: 0, 지민팀: 1~N, 한수팀: N+1~N+M, 싱크: MAX-1
void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    makeEdge(S, i, x);
    sumA += x;
  }
  for(int i = N + 1; i <= N + M; i++) {
    int x; cin >> x;
    makeEdge(i, T, x);
    sumB += x;
  }
}

// Edmond-Karp 알고리즘
int EdmondKarp() {
  int totalFlow = 0;
  int prev[MAX];
  Edge *path[MAX];

  while (true) {
    fill(prev, prev + MAX, -1);
    queue<int> q;
    q.push(S); // 싱크에서 시작

    while (!q.empty() && prev[T] == -1) {
      int cur = q.front();
      q.pop();
      for (Edge *e : adj[cur]) {
        int next = e->to;

        // 용량이 남아있고, 방문하지 않았으면
        if (e->spare() > 0 && prev[next] == -1) {
          q.push(next);
          prev[next] = cur;
          path[next] = e;
          if (next == T)
            break; // 싱크 도착
        }
      }
    }

    // 싱크에 도달하지 못했으면 끝
    if (prev[T] == -1)
      break;

    // 최대유량을 찾고 각 간선에 흘러보내기
    for (int i = T; i != S; i = prev[i]) {
      path[i]->addFlow(1);
    }

    totalFlow += 1;
  }

  return totalFlow;
}

void findPath(int src, int snk) {
  for(auto i : adj[src]) {
    if(i->to == snk) {
      if(i->f == 0) return;
    }
  }
  
  int prev[MAX];
  Edge *path[MAX];
  fill(prev, prev + MAX, -1);
  
  queue<int> q;
  q.push(src);
  
  while(!q.empty() && prev[snk] == -1) {
    int cur = q.front();
    q.pop();

    for(Edge *e : adj[cur]) {
      int next = e->to;
      if(cur < src || (cur == src && next < snk))
        continue;
      if(e->spare() > 0 && prev[next] == -1) {
        q.push(next);
        path[next] = e;
        prev[next] = cur;
      }
    }
  }
  
  if(prev[snk] == -1) return;

  for(auto i : adj[src]) {
    if(i->to == snk) {
      i->f = 0;
      break;
    }
  }
  for(auto i : adj[snk]) {
    if(i->to == src) {
      i->f = 0;
      break;
    }
  }
  for(int i = snk; i != src; i = prev[i]) {
    path[i]->addFlow(1);
  }
}

void solve() {
  if(sumA != sumB) { cout << -1; return; }
  
  for(int i = 1; i <= N; i++) {
    for(int j = N + 1; j <= N + M; j++) {
      makeEdge(i, j, 1);
    }
  }

  int flow = EdmondKarp();
  if(flow != sumA) {cout << -1; return; }

  for(int i = 1; i <= N; i++) {
    for(int j = N + 1; j <= N + M; j++) {
      findPath(i, j);
    }
  }
  
  for(int i = 1; i <= N; i++) {
    for(Edge* e : adj[i]) {
      if(e-> to != S) cout << e->f;
    }
    cout << '\n';
  }
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