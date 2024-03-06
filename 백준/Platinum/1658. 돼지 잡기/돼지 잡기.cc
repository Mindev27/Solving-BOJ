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
const int MAX = 1010;

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

int N, M, S = MAX - 2, T = MAX - 1;
vector<Edge*> adj[MAX];
vector<int> keys[MAX];

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

void input() {
  cin >> M >> N;
  for(int i = 1; i <= M; i++) {
    int x; cin >> x;
    makeEdge(N + i, T, x);
  }

  for(int i = 1; i <= N; i++) {
    int keyNum; cin >> keyNum;
    for(int j = 0; j < keyNum; j++) {
      int key; cin >> key;
      keys[key].push_back(i);
      makeEdge(i, N + key, INF);
    }
    int want; cin >> want;
    makeEdge(S, i, want);
  }
}

// Edmond-Karp 알고리즘
int EdmondKarp() {
  int totalFlow = 0;
  int prev[MAX];   // 이전에 방문한 정점 정보
  Edge *path[MAX]; // 이전으로 가기위한 간선 정보

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
    totalFlow += flow;
  }
  
  return totalFlow;
}

void solve() {
  for(int i = 1; i <= M; i++) {
    if(keys[i].size() == 0) continue;
    for(int j = 0; j < keys[i].size(); j++) {
      if(j == keys[i].size() - 1) continue;
      makeEdge(keys[i][j + 1], keys[i][j], INF);
    }
  }

  cout << EdmondKarp();
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  init();
  input();
  solve();

  return 0;
}