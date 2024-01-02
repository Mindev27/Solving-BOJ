#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int n;

// 투 포인터 알고리즘
void solve() {
  long long start = 1, end = 1;
  bool existed = false;
  
  while (true) {
    if (end * end - start * start == n) { // 된다면 출력
      existed = true;
      cout << end << '\n';
    }
    
    // 차이가 n보다 더 큰데 차이가 1인경우
    if (end - start == 1 && end * end - start * start > n) 
      break;
    
    // 차이가 n보다 더 컸을 때
    if (end * end - start * start > n) start++;
    // 차이가 n보다 더 작았을 때
    else end++;
  }
  // 존재하지 않았으면 -1
  if (!existed)
    cout << -1;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  solve();

  return 0;
}
