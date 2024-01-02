#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

int N, S, E;
vector<int> adj[100005];
vector<int> path;
vector<int> result;

void input() {
  cin >> N >> S >> E;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
}

// 시작지점에서 끝지점까지 경로 탐색
void findPath(int current, vector<int> &path, vector<bool> &visited) {
  visited[current] = true;

  path.push_back(current);

  if (current == E) {
    result = path;
    return;
  }

  for (int i = 0; i < adj[current].size(); i++) {
    int next = adj[current][i];
    if (!visited[next]) {
      findPath(next, path, visited);
      if (!result.empty()) {
        return;
      }
    }
  }
  path.pop_back();
}

void solve() {
  vector<bool> visited(N, false);
  findPath(S, path, visited);

  // 목적지가 아닌 짝수번째 노드에서 길이 2개 이상이면 후공 승
  for(int i = 0; i < result.size(); i++){
    if(i % 2 == 1 && i != result.size() - 1){
      int cur = result[i];
      if(adj[cur].size() > 2){
        cout << "Second";
        return;
      }
    }
  }
  cout << "First";
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
