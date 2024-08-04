#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 0x3f3f3f3f;
const int MAX = 5555;
const int bMAX = 1e7;

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


int N, M, S = 5005, T;
pii posK, posH;
vector<Edge*> adj[MAX];
char board[55][55];
int alpha[30];

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

// i*M+j : numbering / i*2 : in / i*2+1 : out
inline int num(int x, int y) { return x * M + y; }
inline int in(int node) { return node * 2; }
inline int out(int node) { return node * 2 + 1; }


void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    string s; cin >> s;
    for(int j = 0; j < M; j++) {
      board[i][j] = s[j];
      if(board[i][j] == '*') {
        T = in(num(i, j));
      }
    }
  }

  for(int i = 0; i < 26; i++) {
    cin >> alpha[i];
  }
}

void solve() {
  // 내부 in-out 연결
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(board[i][j] == '-' || board[i][j] == '*')
        continue;

      int curW = alpha[board[i][j] - 'A'] + bMAX;
      makeEdge(in(num(i, j)), out(num(i, j)), curW);
    }
  }
  // 인접한 정점 in-out 연결
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(board[i][j] == '-') continue;

      if(i + 1 < N && board[i + 1][j] != '-') {
        makeEdge(out(num(i+1, j)), in(num(i, j)), INF);
        makeEdge(out(num(i, j)), in(num(i+1, j)), INF);
      }
      
      if(j + 1 < M && board[i][j + 1] != '-') {
        makeEdge(out(num(i, j)), in(num(i, j+1)), INF);
        makeEdge(out(num(i, j+1)), in(num(i, j)), INF);
      }
    }
  }

  // Sout과 외곽의 in을 연결
  for(int j = 0; j < M; j++) {
    if(board[0][j] != '-')   makeEdge(S, in(num(0, j)), INF);
    if(board[N-1][j] != '-') makeEdge(S, in(num(N - 1, j)), INF);
  }
  for(int i = 1; i < N - 1; i++) {
    if(board[i][0] != '-')   makeEdge(S, in(num(i, 0)), INF);
    if(board[i][M-1] != '-') makeEdge(S, in(num(i, M - 1)), INF);
  }

  cout << EdmondKarp() % bMAX << endl;
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