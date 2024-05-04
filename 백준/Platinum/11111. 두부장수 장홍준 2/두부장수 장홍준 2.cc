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
int dubu[6][6] = {
  {10, 8, 7, 5, 0, 1},
  {8, 6, 4, 3, 0, 1},
  {7, 4, 3, 2, 0, 1},
  {5, 3, 2, 2, 0, 1},
  {0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0}
};

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
int board[MAX][MAX];
vector<Edge *> adj[MAX];

// 간선 만드는 함수
void makeEdge(int from, int to, int c, int w) {

  Edge *e1 = new Edge(to, c, w), *e2 = new Edge(from, 0, -w);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

void input() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string temp;
    cin >> temp;
    for (int j = 1; j <= M; j++) {
      board[i][j] = temp[j - 1] - 'A';
    }
  }
}

pii SPFA() {
  int totalCost = 0, totalFlow = 0;

  while (true) {
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

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      inQ[cur] = false;

      for (Edge *e : adj[cur]) {
        int next = e->to;
        if (e->spare() > 0 && dist[next] > dist[cur] + e->w) {
          dist[next] = dist[cur] + e->w;
          prev[next] = cur;
          path[next] = e;

          if (!inQ[next]) {
            q.push(next);
            inQ[next] = true;
          }
        }
      }
    }

    // 싱크에 도달하지 못했으면 끝
    if (prev[T] == -1)
      break;

    // 최대유량을 찾고 각 간선에 흘러보내기
    int flow = INF;
    for (int i = T; i != S; i = prev[i]) {
      flow = min(flow, path[i]->spare());
    }
    for (int i = T; i != S; i = prev[i]) {
      totalCost += flow * path[i]->w;
      path[i]->addFlow(flow);
    }
    totalFlow += flow;
  }

  return {totalFlow, totalCost};
}

// 인접한 것들끼리 그래프 연결
void solve() {
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      int curIndex = (i - 1) * M + j;
      int cur = board[i][j];
      
      if((i + j) % 2 == 0) {
        makeEdge(S, curIndex, 1, 0);
        for(int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          
          if(nx < 1 || nx > N || ny < 1 || ny > M)
            continue;

          int nxt = board[nx][ny];
          int nxtIndex = (nx - 1) * M + ny;
          makeEdge(curIndex, nxtIndex, 1, -dubu[cur][nxt]);
        }
      }        
      makeEdge(curIndex, T, 1, 0);
    }
  }

  pii ans = SPFA();
  cout << -ans.Y;
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