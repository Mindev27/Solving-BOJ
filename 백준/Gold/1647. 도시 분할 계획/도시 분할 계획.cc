#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

const int MAX = 100001;
vector<pair<int, int>> linked[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dist;
bool visited[MAX] = {};

int prim(int n);

int main() {
  int v, e;
  cin >> v >> e;

  // 간선 정보 저장
  for(int i = 0; i < e; i++) {
    int start, end, weight;
    cin >> start >> end >> weight;

    linked[start].push_back({weight, end});
    linked[end].push_back({weight, start});
  }

  cout << prim(v);
}

// 프림 알고리즘
int prim(int n) {
  int result = 0;
  int selectedMax = 0; // 선택된 간선 중 가중치가 가장 큰 간선

  //초기화
  for(int i = 1; i <= n; i++)
    visited[i] = false;


  dist.push({0, 1}); // 1로 시작

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
    selectedMax = max(selectedMax, minDist);
    visited[cur] = true; // 방문표시
    for(auto next: linked[cur]){ // 연결된 정점의 다음 정점들과 가중치 정보 전달
      dist.push(next);
    }
  }
  
  result -= selectedMax;

  return result;
}