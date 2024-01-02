#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int parent[MAX] = {};
vector<pair<int, pair<int, int>>> map; // 가중치, 시작노드, 끝노드

int getParent(int x);
void unionParent(int a, int b);
bool findParent(int a, int b);
long long int kruskal(int n);

int main() {	
  int n;
  cin >> n;

  // 값 초기화
  for(int i = 1; i <= n; i++)
    parent[i] = i;

  // 입력
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int a; cin >> a;
      if(i != j){
        map.push_back({a, {i, j}});
      }
    }
  }

  // 가중치를 기준으로 정렬
  sort(map.begin(), map.end());

  long long int result = kruskal(n);
  cout << result;
}

// 크루스칼 알고리즘
long long int kruskal(int n){
  long long int result = 0;
  int lineNum = 0;
  
  for(int i = 0; i < map.size(); i++){
    int weight = map[i].first;
    int startNode = map[i].second.first;
    int endNode = map[i].second.second;

    // MST라면 break
    if(lineNum == n - 1)
      break;
    
    //유니온 파인드로 간선을 선택할수 있는지 확인
    if(findParent(startNode, endNode)) continue;

    result += weight;
    lineNum++;
    unionParent(startNode, endNode);
  }

  return result;
}
  
// 부모를 찾는 함수
int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

// 두 값을 하나의 유니온으로 묶는 함수
void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y) parent[x] = y;
  else parent[y] = x;
}

// 둘의 부모 노드가 같은지 확인
bool findParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x == y)
    return true;
  else
    return false;
}