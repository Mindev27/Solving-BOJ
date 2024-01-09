#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int SIZE = 10005;
int N;
int village[SIZE];
vector<int> adj[SIZE];
bool visited[SIZE];
vector<int> tree[SIZE];
int dp[SIZE][2];

void input() {
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> village[i];
  for(int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

// 루트가 1인 트리로 만들기
void makeTree(int start) {
  visited[start] = true;
  for(int i = 0; i < adj[start].size(); i++) {
    int next = adj[start][i];
    if(!visited[next]){
      tree[start].push_back(next);
      makeTree(next);
    }
  }
}

int DFS(int cur, int special) {
  if(dp[cur][special] != -1) // 메모이제이션
    return dp[cur][special];

  // 우수 마을이 아닌경우(다음 마을은 상관X)
  if(special == 0){ 
    dp[cur][special] = 0;
    for(int i = 0; i < tree[cur].size(); i++) {
      int next = tree[cur][i];
      dp[cur][special] += max(DFS(next, 0), DFS(next, 1));
    }
  }
  else{ // 우수 마을인 경우(다음마을은 무조건 일반 마을)
    dp[cur][special] = village[cur];
    for(int i = 0; i < tree[cur].size(); i++) {
      int next = tree[cur][i];
      dp[cur][special] += DFS(next, 0);
    }
  }
  return dp[cur][special];
}

void solve() {
  makeTree(1);
  memset(dp, -1, sizeof(dp));
  cout << max(DFS(1, 0), DFS(1, 1));
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
