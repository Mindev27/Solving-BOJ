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

int N, M, K, S = 0, T = MAX - 1, Ktemp = MAX - 2;
vector<Edge*> adj[MAX];

// 간선 만드는 함수
void makeEdge(int from, int to, int w) {
  Edge *e1 = new Edge(to, w), *e2 = new Edge(from, 0);
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

// 사람: 1 ~ N, 일: N+1 ~ N+M
void input() {
  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++) { 
    int num; cin >> num;
    while(num--) {
      int x; cin >> x;
      makeEdge(i, N + x, 1); // 사람 -> 일
    }
    makeEdge(S, i, 1); // src -> 사람
  }

  for(int i = 1; i <= M; i++) // 일 -> sink
    makeEdge(N + i, T, 1);

  // 추가 간선
  makeEdge(S, Ktemp, K);
  for(int i = 1; i <= N; i++)
    makeEdge(Ktemp, i, INF);
}

// Edmond-Karp 알고리즘
void EdmondKarp() {
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

  cout << ans;
}


int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  init();
  input();
  EdmondKarp();

  return 0;
}