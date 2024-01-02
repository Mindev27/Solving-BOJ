#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 100001;
vector<pair<long, long>> linked[MAX];
priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> dist;
bool visited[MAX] = {};

long prim(int n);

int main() {
  long v, e, total = 0;
  cin >> v >> e;

  // 간선 정보 저장
  for(int i = 0; i < e; i++) {
    int start, end, weight;
    cin >> start >> end >> weight;

    total += weight;
    linked[start].push_back({weight, end});
    linked[end].push_back({weight, start});
  }

  long res = prim(v);

  if(res == -1) cout << -1;
  else cout << total - res;
}

// 프림 알고리즘
long prim(int n) {
  long result = 0;

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

    if(minDist == INT_MAX) return -1; // 연결할 간선이 없다면 불가능

    result += minDist; // 전체값에 더해주기
    visited[cur] = true; // 방문표시
    for(auto next: linked[cur]){ // 연결된 정점의 다음 정점들과 가중치 정보 전달
      dist.push(next);
    }
  }

  return result;
}