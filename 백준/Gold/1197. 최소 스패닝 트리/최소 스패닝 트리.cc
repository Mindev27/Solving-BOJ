#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 10001;
// index: 해당하는 정점, first: 연결된 정점, second: 가중치
vector<pair<int, int>> linked[MAX];
int dist[MAX] = {};     // 선택된 노드와 idx노드가 연결될때 최소비용
bool visited[MAX] = {}; // idx가 선택된 노드인지 판별

int prim(int n);

int main() {
  
  int v, e;
  cin >> v >> e;

  // 간선 정보 저장
  for(int i = 0; i < e; i++) {
    int start, end, weight;
    cin >> start >> end >> weight;

    linked[start].push_back({end, weight});
    linked[end].push_back({start, weight});
  }

  cout << prim(v);
}

// 프림 알고리즘
int prim(int n) {
  int result = 0;

  //초기화
  for(int i = 1; i <= n; i++){
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  dist[1] = 0; // 1로 시작

  for(int i = 1; i <= n; i++){
    int cur, minDist = INT_MAX;
    
    for(int j = 1; j <= n; j++){ 
      // 선택하지 않았고, 가장 작은 간선 선택
      if(!visited[j] && dist[j] < minDist){ 
        minDist = dist[j];
        cur = j;
      }
    }

    result += minDist; // 전체값에 더해주기
    visited[cur] = true; // 방문표시
    for(auto next: linked[cur]){ // cur노드와 연결된 정점의 정보와 가중치로 업데이트
      dist[next.first] = min(dist[next.first], next.second);
    }
  }

  return result;
}