#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int SIZE = 1000005;
int N;
vector<int> adj[SIZE];
bool visited[SIZE];
vector<int> tree[SIZE];
int dp[SIZE][2];

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
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

  
  if(special == 0){ // 일반인인 경우 얼리어답터 필요
    dp[cur][special] = 0;
    for(int i = 0; i < tree[cur].size(); i++) {
      int next = tree[cur][i];
      dp[cur][special] += DFS(next, 1);
    }
  }
  else{ // 얼리어답터인 경우 둘다 가능
    dp[cur][special] = 1;
    for(int i = 0; i < tree[cur].size(); i++) {
      int next = tree[cur][i];
      dp[cur][special] += min(DFS(next, 0), DFS(next, 1));
    }
  }
  return dp[cur][special];
}

void solve() {
  makeTree(1);
  memset(dp, -1, sizeof(dp));
  cout << min(DFS(1, 0), DFS(1, 1));
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
