#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 200001;
vector<pair<long, long>> linked[MAX];
priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> dist;
bool visited[MAX] = {};

long prim(int n);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  while(true){
    long houseNum, roadNum, total = 0;
    cin >> houseNum >> roadNum;
    
    if(houseNum == 0 && roadNum == 0) break;

    // 초기화
    for(int i = 0; i <= houseNum; i++)
      linked[i].clear();
      
    // 간선 정보 저장
    for(int i = 0; i < roadNum; i++) {
      int start, end, weight;
      cin >> start >> end >> weight;
  
      total += weight;
      linked[start].push_back({weight, end});
      linked[end].push_back({weight, start});
    }
  
    cout << total - prim(houseNum) << "\n";
  }  
}

// 프림 알고리즘
long prim(int n) {
  long result = 0;

  //초기화
  for(int i = 0; i <= n; i++)
    visited[i] = false;
  while(!dist.empty())
    dist.pop();

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
    visited[cur] = true; // 방문표시
    for(auto next: linked[cur]){ // 연결된 정점의 다음 정점들과 가중치 정보 전달
      dist.push(next);
    }
  }

  return result;
}
