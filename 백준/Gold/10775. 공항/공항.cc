#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int parent[MAX] = {};

int getParent(int x);
void unionParent(int a, int b);

int main() {	
  int n, m;
  cin >> n >> m;

  // 값 초기화
  for(int i = 0; i <= n; i++)
    parent[i] = i;

  int result = 0;
  
  for(int i = 0; i < m; i++){
    int x; cin >> x;

    int parentX = getParent(x);
    
    if(parentX == 0) break;

    unionParent(parentX, parentX - 1);
    result++;
  }

  cout << result;
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
