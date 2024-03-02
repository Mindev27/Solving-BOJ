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

const int MAX = 25555;

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

int N, M, S, T;
pii posK, posH;
vector<Edge*> adj[MAX];
char board[105][105];

// 간선 만드는 함수
void makeEdge(int from, int to, int w) {
  Edge *e1 = new Edge(to, w), *e2 = new Edge(from, 0);
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
        }
      }
    }

    // 싱크에 도달하지 못했으면 끝
    if(prev[T] == -1) break;

    for(int v = T; v != S; v = prev[v]){
      if(v != T && v != S + 1) path[v]->addFlow(1);
    }

    ans++;
  }
  return ans;
}

void input() {
  cin >> N >> M;
  
  // 보드 입력
  for(int i = 0; i < N; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < M; j++) {
      board[i][j] = temp[j];
      if(board[i][j] == 'K') {
        S = (i*M+j) * 2;
        posK = {i, j};
      }
      else if(board[i][j] == 'H') {
        T = (i*M+j) * 2 + 1;
        posH = {i, j};
      }
      makeEdge((i*M+j) * 2, (i*M+j) * 2 + 1, 1);
    }
  }
}

void solve() {
  // K H가 붙어있으면 불가능
  if(abs(posK.X - posH.X) + abs(posK.Y - posH.Y) <= 1){
    cout << -1;
    return;
  }

  for(int i = 0; i < N; i++) { // 각 정점을 간선으로 연결하기
    for(int j = 0; j < M; j++) {
      if(board[i][j] == '#') continue;
      if(i + 1 < N && board[i + 1][j] != '#') {
        makeEdge((i*M+j) * 2 + 1, ((i+1)*M+j) * 2, 1);
        makeEdge(((i+1)*M+j) * 2 + 1, (i*M+j) * 2, 1);
      }
      if(j + 1 < M && board[i][j + 1] != '#') {
        makeEdge((i*M+j) * 2 + 1, (i*M+j+1) * 2, 1);
        makeEdge((i*M+j+1) * 2 + 1, (i*M+j) * 2, 1);
      }
    }
  }

  cout << EdmondKarp();
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