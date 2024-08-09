#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 0x3f3f3f3f;
const int MAX = 2005;

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


int N, M, S = 2003, T = 2004;
vector<Edge*> adj[MAX];
vector<pair<pii, int>> sharks;

// 간선 만드는 함수
void makeEdge(int from, int to, int c) {
  Edge *e1 = new Edge(to, c), *e2 = new Edge(from, 0);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

// Edmond-Karp 알고리즘
int EdmondKarp() {
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

// 왼(0~N-1) -> 오(N ~ 2N-1)
void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a, b, c; cin >> a >> b >> c;
    sharks.push_back({{a, b}, c});
  }
}

void solve() {
  for(int i = 0; i < N; i++) {
    makeEdge(S, i, 2);
    makeEdge(i+N, T, 1);
  }

  // 먹을 수 있다면 왼 -> 오 연결
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j) continue;

      if(sharks[i].X.X == sharks[j].X.X && sharks[i].X.Y == sharks[j].X.Y && sharks[i].Y == sharks[j].Y && i > j) {
        continue;
      }
      bool canEatj = true;
      if(sharks[i].X.X < sharks[j].X.X) canEatj = false;
      if(sharks[i].X.Y < sharks[j].X.Y) canEatj = false;
      if(sharks[i].Y < sharks[j].Y) canEatj = false;

      if(canEatj) makeEdge(i, j+N, 1);
    }
  }

  cout << N - EdmondKarp() << '\n';
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
