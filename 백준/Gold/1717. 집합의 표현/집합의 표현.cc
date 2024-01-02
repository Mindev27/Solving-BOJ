#include <iostream>

using namespace std;

int map[1000001];
int n, m;

int getParent(int x);
void unionParent(int a, int b);
void findParent(int a, int b);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    map[i] = i;
  }

  for(int i = 0; i < m; i++){
    int cmd, a, b;
    cin >> cmd >> a >> b;

    if(cmd == 0) 
      unionParent(a, b); // 삽입 연산
      
    else
      findParent(a, b); // 확인 연산
  }
}

// 부모를 찾는 함수
int getParent(int x) {
  if (map[x] == x) return x;
  return map[x] = getParent(map[x]);
}

// 두 값을 하나의 유니온으로 묶는 함수
void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y) map[x] = y;
  else map[y] = x;
}

// 둘의 부모 노드가 같은지 확인
void findParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x == y) cout << "YES\n";
  else cout << "NO\n";
}