#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> adj[300005];

void input() {
  cin >> N >> K;
  for(int i = 0; i < N - 1; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second < b.second;
}

// v를 루트노드로 잡고, 부모가 b일때
// (최적의 집합 개수, 이 정점을 포함할때 정점개수 최솟값)
pair<int, int> solve(int v, int b) {
  vector<pair<int, int>> child;
  for(int i = 0; i < adj[v].size(); i++){
    int next = adj[v][i];
    if(next == b) continue;
    child.push_back(solve(next, v));
  }

  // 정점개수가 작은것부터 확인하기 위해 오름차순 정렬
  sort(child.begin(), child.end(), compare);

  // 자식들의 최적 노드개수 합 구하기
  int cnt = 0;
  for(int i = 0; i < child.size(); i++)
    cnt += child[i].first;

  // 자식 정점과 안묶일때로 초기화
  int x = cnt + 1, y = 1;
  
  // 하나씩 확인하면서 묶일때 더 최적으로 가는 경우 업데이트
  // 자식들중 하나랑 묶일때
  if(child.size() >= 1 && child[0].second <= K){
    if(x > cnt) {x = cnt; y = child[0].second + 1;}
    else if(x == cnt) {
      if(y > child[0].second + 1) y = child[0].second + 1;
    }
  }

  // 자식들중 두개랑 묶일때
  if(child.size() >= 2 && child[0].second + child[1].second <= K) {
    if(x > cnt - 1) {x = cnt - 1; y = K + 1;}
    else if(x == cnt - 1) {
      if(y > K + 1) y = K + 1;
    }
  }

  return {x, y};
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  auto result = solve(1, -1);
  cout << result.first;
  return 0;
}
