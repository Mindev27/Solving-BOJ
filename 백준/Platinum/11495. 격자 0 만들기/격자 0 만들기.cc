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
const int MAX = 2505;

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
int totalSum = 0;
int arr[55][55] = {};
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
  totalSum = 0;
  memset(arr, 0, sizeof(arr));
}

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> arr[i][j];
      totalSum += arr[i][j];
    }
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

void generate() {
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      int cur = arr[i][j];
      int curIdx = (i - 1) * M + j;

      // 격자에 따라 소스또는 싱크와 연결
      if((i + j) % 2 == 0) makeEdge(S, curIdx, cur);
      else makeEdge(curIdx, T, cur);

      if((i + j) % 2 == 1) continue;

      // 인접한 칸끼리 INF의 용량으로 연결
      for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        int nextIdx = (nx - 1) * M + ny;
        
        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
        
        makeEdge(curIdx, nextIdx, INF);
      }
    }
  }
}

void solve() {
  generate();
  cout << totalSum - EdmondKarp() << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    init();
    input();
    solve();
  }

  return 0;
}