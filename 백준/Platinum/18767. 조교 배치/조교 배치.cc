#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <limits>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MAX = 10010;
const int INF = numeric_limits<int>::max();

struct Edge {
  int to, capacity, flow;
  Edge *reverse;
  Edge(int to, int capacity) : to(to), capacity(capacity), flow(0), reverse(nullptr) {}

  int residual() const { return capacity - flow; }
  void addFlow(int amount) {
    flow += amount;
    reverse->flow -= amount;
  }
};

vector<Edge*> adj[MAX];
int N, S, T;
int level[MAX];
int work[MAX];

void addEdge(int from, int to, int capacity) {
  Edge *forward = new Edge(to, capacity), *backward = new Edge(from, 0);
  forward->reverse = backward;
  backward->reverse = forward;
  adj[from].push_back(forward);
  adj[to].push_back(backward);
}

bool bfs() {
  fill(level, level + MAX, -1);
  queue<int> q;
  level[S] = 0;
  q.push(S);

  while (!q.empty()) {
    int cur = q.front(); q.pop();

    for (Edge *edge : adj[cur]) {
      if (level[edge->to] == -1 && edge->residual() > 0) {
        level[edge->to] = level[cur] + 1;
        q.push(edge->to);
      }
    }
  }

  return level[T] != -1;
}

int dfs(int cur, int flow) {
  if (cur == T) return flow;
  for (int &i = work[cur]; i < adj[cur].size(); ++i) {
    Edge *edge = adj[cur][i];
    if (level[edge->to] == level[cur] + 1 && edge->residual() > 0) {
      int df = dfs(edge->to, min(flow, edge->residual()));
      if (df > 0) {
        edge->addFlow(df);
        return df;
      }
    }
  }
  return 0;
}

int dinic() {
  int totalFlow = 0;

  while (bfs()) {
    fill(work, work + MAX, 0);
    while (int flow = dfs(S, INF)) {
      totalFlow += flow;
    }
  }

  return totalFlow;
}

void init() {
  for (int i = 0; i < MAX; ++i) {
    for (Edge *edge : adj[i]) delete edge;
    adj[i].clear();
  }
}

void input() {
  cin >> N;
  S = 0; T = N + 4;

  for (int i = 1; i <= N; ++i) {
    addEdge(S, i, 1);
  }

  for (int i = 1; i <= 3; ++i) {
    int x; cin >> x;
    addEdge(N + i, T, x);
  }

  for (int i = 1; i <= 3; ++i) {
    int m; cin >> m;
    for (int j = 0; j < m; ++j) {
      int assist; cin >> assist;
      addEdge(assist, N + i, 1);
    }
  }
}

void solve() {
  cout << dinic() << '\n';

  for (int i = 1; i <= N; ++i) {
    for (Edge *e : adj[i]) {
      if (e->flow > 0) {
        cout << i << ' ';
        if (e->to == N + 1) cout << "A\n";
        else if (e->to == N + 2) cout << "B\n";
        else if (e->to == N + 3) cout << "C\n";
        break;
      }
    }
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int Tc;
  cin >> Tc;
  while (Tc--) {
    init();
    input();
    solve();
  }
  return 0;
}
