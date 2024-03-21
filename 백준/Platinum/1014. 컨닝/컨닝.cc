#include <algorithm>
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
const int MAX = 150;

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

int N, M, S, T, leftSeat;
char board[15][15] = {};
vector<Edge*> adj[MAX];
int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {1, -1, 1, -1, 1, -1};

// 간선 만드는 함수
void makeEdge(int from, int to, int w) {
  Edge *e1 = new Edge(to, w), *e2 = new Edge(from, 0);
  e1->dual = e2;
  e2->dual = e1;
  adj[from].push_back(e1);
  adj[to].push_back(e2);
}

void init() {
  leftSeat = 0;
  for(int i = 0 ; i < MAX; i++) {
    adj[i].clear();
  }
}

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < M; j++) {
      board[i][j] = temp[j];
      if(board[i][j] == '.') leftSeat++;
    }
  }
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

// 소스 -> 홀수 열 -> 짝수 열 -> 싱크
void solve() {
  S = MAX - 1; // source
  T = MAX - 2; // sink
  
  // 홀수 열 -> 짝수 열
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j += 2) {
      int nodeNum = i * M + j;

      if(board[i][j] == '.') {
        for(int k = 0; k < 6; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          int nextNum = nx * M + ny;

          if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

          if(board[nx][ny] == 'x')
            continue;

          makeEdge(nodeNum, nextNum, 1);
        }
      }
    }
  }

  // 소스와 홀수열을 연결
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j += 2){
      if(board[i][j] == 'x') continue;

      int nodeNum = i * M + j;
      makeEdge(S, nodeNum, 1);
    }
  }

  // 싱크와 짝수열을 연결
  for(int i = 0; i < N; i++) {
    for(int j = 1; j < M; j += 2){
      if(board[i][j] == 'x') continue;

      int nodeNum = i * M + j;
      makeEdge(nodeNum, T, 1);
    }
  }

  cout << leftSeat - EdmondKarp() << '\n';
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