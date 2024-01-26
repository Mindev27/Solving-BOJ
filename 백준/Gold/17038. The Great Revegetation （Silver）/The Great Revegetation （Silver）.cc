#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N, M;
int parent[200005] = {}; // 1~N : 목초지, N+1~2N : ~목초지

int getParent(int x) {
  if (parent[x] == -1) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if(x == y) return;
  if (x >= N + 1) parent[x] = y;
  else parent[y] = x;
}

void input() {
  cin >> N >> M;
  memset(parent, -1, sizeof(parent));
  
  for(int i = 0; i < M; i++) {
    char a; int b, c;
    cin >> a >> b >> c;
    
    if(a == 'S') { // b, c가 같은 집합이고 ~b, ~c도 같은 집합
      unionParent(b, c);
      unionParent(b + N, c + N);
    }
    else{ // b, c가 다른 집합이므로 b <-> ~c, c <-> ~b
      unionParent(b, c + N);
      unionParent(c, b + N);
    }
  }
}


void solve() {
  for(int i = 1; i <= N; i++) {
    if(getParent(i) == getParent(i + N)){ // 모순인 경우
      cout << "0";
      return;
    }
  }

  for(int i = 1; i <= N; i++) // i와 ~i를 합치기
    unionParent(i, i + N);

  // 모든 경우의 수는 2^(집합개수)이다
  cout << "1"; 
  for(int i = 1; i <= N; i++)
    if(i == getParent(i)) cout << "0";
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}