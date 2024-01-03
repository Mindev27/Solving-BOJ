#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 4000005;
int N, M, K;
int minsu[SIZE] = {};
int chulsu[SIZE] = {};
int parent[SIZE] = {};

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x < y) parent[x] = y; // 큰 수를 반환하기 위함
  else parent[y] = x;
}

void input() {
  cin >> N >> M >> K;
  for(int i = 0; i < M; ++i){
    cin >> minsu[i];
    parent[i] = i;
  }
  for(int i = 0; i < K; ++i)
    cin >> chulsu[i];

}

void solve() {
  sort(minsu, minsu + M);

  for(int i = 0; i < K; ++i) {
    int cur = chulsu[i];

    // cur보다 처음으로 큰 수가 나오는 인덱스
    int index = lower_bound(minsu, minsu + M, cur + 1) - minsu;

    cout << minsu[getParent(index)] << '\n';

    // 낸 숫자는 다음 숫자와 집합으로 묶기
    if(index != M - 1) unionParent(getParent(index), getParent(index) + 1);
  }
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