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

const int MAX = 110;
const int INF = 1e9;
int N, S, T;
int capacity[MAX][MAX]; // 용량
int flow[MAX][MAX];     // 유량
vector<int> adj[MAX];   // 각 정점에서 출발하는 간선 정보

void init() {
  memset(capacity, 0, sizeof(capacity));
  memset(flow, 0, sizeof(flow));
  for (int i = 0; i < MAX; i++) {
    adj[i].clear();
  }
}

// 소스: 0, 보조조교: 1 ~ N,
// 실험실(A~C): N+1 ~ N+3, 싱크: N + 4
void input() {
  cin >> N;
  S = 0;
  T = N + 4;

  // S에서 보조조교 간선 정보 만들
  for(int i = 1; i <= N; i++) {
    adj[S].push_back(i);
    capacity[S][i] = 1;
  }

  // 실험실 용량 입력
  for(int i = 1; i <= 3; i++) {
    int x; cin >> x;
    capacity[N + i][T] = x;
    adj[N + i].push_back(T);
  }

  for(int i = 1; i <= 3; i++) {
    int lab = N + i;     // 실험실 번호
    int num; cin >> num; // 실험실에 지원한 인원
    
    for(int j = 0; j < num; j++) {
      int x; cin >> x;
      adj[x].push_back(lab);
      adj[N + i].push_back(x); // 역방향 간선
      capacity[x][lab] = 1;
    }
  }
}

int EdmondsKarp(int source, int sink) {
  int totalFlow = 0;
  while (true) {
    vector<int> parent(MAX, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);

    while (!q.empty() && parent[sink] == -1) {
      int curr = q.front();
      q.pop();

      for (int next : adj[curr]) {
        // 용량이 남아있고 아직 방문하지 않았다면
        if (capacity[curr][next] - flow[curr][next] > 0 && parent[next] == -1) {
          q.push(next);
          parent[next] = curr;
          if (next == sink)
            break; // 싱크에 도달했다면 중단
        }
      }
    }

    if (parent[sink] == -1)
      break; // 더 이상 증가 경로가 없다면 종료

    int amount = INF;
    for (int p = sink; p != source; p = parent[p]) {
      amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
    }
    for (int p = sink; p != source; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }
    totalFlow += amount;
  }

  return totalFlow;
}

void solve() {
  cout << EdmondsKarp(S, T) << '\n';
  
  for (int i = 1; i <= N; i++) {
    for (int j = N + 1; j <= N + 3; j++) {
      if (flow[i][j] > 0) {
        cout << i << " ";
        if (j == N + 1) cout << "A\n";
        else if (j == N + 2) cout << "B\n";
        else if (j == N + 3) cout << "C\n";
        break;
      }
    }
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc;
  cin >> Tc;
  while (Tc--) {
    init();
    input();
    solve();
  }

  return 0;
}
