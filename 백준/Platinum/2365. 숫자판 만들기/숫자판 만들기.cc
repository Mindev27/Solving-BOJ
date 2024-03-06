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
int totalSum = 0;       // 플로우의 합이 되어야함
vector<int> nums[2];    // 입력을 저장할 벡터
vector<Edge*> adj[MAX]; // 간선 정보

// 간선 만드는 함수
void makeEdge(int from, int to, int w) {
  Edge *e1 = new Edge(to, w), *e2 = new Edge(from, 0);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

void init() {
  for(int i = 0; i < MAX; i++)
    adj[i].clear();
}

void input() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    int a; cin >> a;
    totalSum += a;
    nums[0].push_back(a);
  }

  for(int i = N + 1; i <= N * 2; i++) {
    int a; cin >> a;
    nums[1].push_back(a);
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

void generate(int k) {
  for(int i = 1; i <= N; i++)
    makeEdge(S, i, nums[0][i - 1]);

  for(int i = 1; i <= N; i++)
    makeEdge(N + i, T, nums[1][i - 1]);

  for(int cur = 1; cur <= N; cur++) {
    for(int next = N + 1; next <= N * 2; next++) {
      makeEdge(cur, next, k);
    }
  }
}

void solve() {
  int l = 0, r = 10000, mid;
  while(l < r) {
    mid = (l + r) / 2;
    init();
    generate(mid); // 용량이 mid로 만들기

    if(EdmondKarp() < totalSum) // F인 경우
      l = mid + 1;
    else                        // T인 경우
      r = mid;
  }

  init();
  generate(r);
  EdmondKarp();
  
  cout << r << '\n';
  for(int i = 1; i <= N; i++) {
    for(Edge *e : adj[i]) {
      if(N + 1 <= e->to) {
        cout << e->f << ' ';
      }
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