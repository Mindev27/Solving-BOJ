#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10005;
int N;
int w[SIZE];
vector<int> adj[SIZE];
bool visited[SIZE];
vector<int> tree[SIZE];
int dp[SIZE][2];
vector<int> selectedNode;

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> w[i];

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

// 인접 리스트를 루트가 1인 트리로 만들기
void makeTree(int start) {
  visited[start] = true;
  for (int i = 0; i < adj[start].size(); i++) {
    int next = adj[start][i];
    if (!visited[next]) {
      tree[start].push_back(next);
      makeTree(next);
    }
  }
}

int DFS(int cur, int special) {
  if (dp[cur][special] != -1) // 메모이제이션
    return dp[cur][special];

  if (special ==
      0) { // 선택되지 않았을때 다음노드는 선택할수도 하지 않을수도 있음
    dp[cur][special] = 0;
    for (int i = 0; i < tree[cur].size(); i++) {
      int next = tree[cur][i];
      dp[cur][special] += max(DFS(next, 0), DFS(next, 1));
    }
  } else { // 선택되었다면 다음노드는 선택해서는 안됨
    dp[cur][special] = w[cur];
    for (int i = 0; i < tree[cur].size(); i++) {
      int next = tree[cur][i];
      dp[cur][special] += DFS(next, 0);
    }
  }
  return dp[cur][special];
}

void select(int cur, int special) {
  if (special == 1) selectedNode.push_back(cur);

  for (int next : tree[cur]) {
    if (special == 0) { // 현재가 선택안되었다면
      if (dp[next][0] < dp[next][1]) // 최종값이 더 큰 것을 추적
        select(next, 1);
      else
        select(next, 0);
    }
    else // 현재가 선택되었다면
      select(next, 0); // 다음노드는 포함 X
  }
}

void solve() {
  makeTree(1); // 1번을 루트노드로 트리 만들기
  memset(dp, -1, sizeof(dp));

  // 1번노드를 선택할때 선택하지 않을때중 더 큰값
  cout << max(DFS(1, 0), DFS(1, 1)) << '\n';

  // 최대 독립 집합에 속하는 노드들 추적
  // 1이 선택되었는지 안되었는지로 탐색시작
  select(1, (dp[1][0] < dp[1][1]) ? 1 : 0);

  sort(selectedNode.begin(), selectedNode.end());
  for (int node : selectedNode)
    cout << node << ' ';
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