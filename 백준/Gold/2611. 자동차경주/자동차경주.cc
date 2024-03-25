#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int SIZE = 1005;
int N, M, END;
vector<int> adj[SIZE];
int inDegree[SIZE];
int dp[SIZE];
int dist[SIZE][SIZE];
int preV[SIZE];

void input() {
  cin >> N >> M;
  END = N + 1;
  for(int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    if(b != 1) {
      adj[a].push_back(b);
      inDegree[b]++;
      dist[a][b] = c;
    }
    else {
      adj[a].push_back(END);
      inDegree[END]++;
      dist[a][END] = c;
    }
  }
}

// 위상 정렬
vector<int> topologySort() {
  vector<int> res;
  queue<int> q;

  for(int i = 1; i <= N + 1; i++) {
    if(inDegree[i] == 0) {
      res.push_back(i);
      q.push(i);
    }
  }

  for(int i = 0; i < N; i++) {
    int cur = q.front();
    q.pop();

    for(auto next : adj[cur]) {
      if(--inDegree[next] == 0) {
        res.push_back(next);
        q.push(next);
      }
    }
  }

  return res;
}

void solve() {
  vector<int> order = topologySort();

  memset(dp, 0, sizeof(dp));
  for(int i = 0; i <= N + 1; i++) {
    for(int j = 0; j < i; j++) {
      int pre = order[j];
      int cur = order[i];
      if(dist[pre][cur] != 0) {
        if(dp[cur] < dp[pre] + dist[pre][cur]) {
          dp[cur] = dp[pre] + dist[pre][cur];
          preV[cur] = pre;
        }
      }
    }
  }

  vector<int> ans;
  for(int i = END; i != 0; i = preV[i]) {
    ans.push_back(i);
  }

  cout << dp[END] << '\n';
  for(int i = ans.size() - 1; i > 0; i--)
    cout << ans[i] << ' ';
  cout << '1';
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