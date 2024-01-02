#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 10005;
int v, e, start, minNode = INT_MAX;
// index: 해당하는 정점, first: 연결된 정점, second: 가중치
vector<pair<int, int>> linked[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dist; // 선택된 노드와 idx노드가 연결될때 최소비용
int country[MAX];       // 도시의 방문 비용 저장
bool visited[MAX] = {}; // idx가 선택된 노드인지 판별


void input() {
  cin >> v >> e;

  //도시 정보 저장
  for(int i = 1; i <= v; i++){
    cin >> country[i];
    if(minNode > country[i]){
      start = i;
      minNode = country[i];
    }
  }

  // 간선 정보 저장
  for(int i = 0; i < e; i++) {
    int start, end, weight;
    cin >> start >> end >> weight;

    linked[start].push_back({weight * 2 + country[start] + country[end], end});
    linked[end].push_back({weight * 2 + country[start] + country[end], start});
  }
}

// 프림 알고리즘
int prim(int n) {
  int result = minNode; // 시작 도시는 한번 더 방문

  //초기화
  for(int i = 1; i <= n; i++)
    visited[i] = false;


  dist.push({0, start}); // 1로 시작

  for(int i = 1; i <= n; i++){
    int cur, minDist = INT_MAX;

    while(!dist.empty()){
      cur = dist.top().second;
      if(!visited[cur]){
        minDist = dist.top().first;
        break;
      }
      dist.pop();
    }

    result += minDist; // 전체값에 더해주기
    visited[cur] = true; // 방문표시
    for(auto next: linked[cur]){ // 연결된 정점의 다음 정점들과 가중치 정보 전달
      dist.push(next);
    }
  }

  return result;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();

  cout << prim(v);
}