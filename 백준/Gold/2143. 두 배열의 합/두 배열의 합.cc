#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int T, aSize, bSize;
int aSum[1005], bSum[1005];
vector<ll> a, b;

// 누적합으로 배열 저장
void input() {
  cin >> T;
  
  cin >> aSize;
  ll sum = 0;
  for(int i = 1; i <= aSize; ++i){
    int temp; cin >> temp;
    sum += temp;
    aSum[i] = sum;
  }
    
  cin >> bSize;
  sum = 0;
  for(int i = 1; i <= bSize; ++i){
    int temp; cin >> temp;
    sum += temp;
    bSum[i] = sum;
  }
}

void solve() {
  // a, b에서 나올 수 있는 누적합을 모두 계산(중복 허용)
  for(int i = 1; i <= aSize; ++i)
    for(int j = i; j <= aSize; ++j)
      a.push_back(aSum[j] - aSum[i - 1]);

  for(int i = 1; i <= bSize; ++i)
    for(int j = i; j <= bSize; ++j)
      b.push_back(bSum[j] - bSum[i - 1]);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  // 투포인터 탐색
  ll cnt = 0;
  int left = 0, right = b.size() - 1;

  while (left < a.size() && right >= 0) {
    ll curSum = a[left] + b[right];

    if (curSum == T) {
      ll leftCnt = 1, rightCnt = 1;
      while (left + 1 < a.size() && a[left] == a[left + 1]) {
        left++;
        leftCnt++;
      }
      while (right - 1 >= 0 && b[right] == b[right - 1]) {
        right--;
        rightCnt++;
      }
      cnt += leftCnt * rightCnt;
      left++;
      right--;
    }
    else if (curSum < T) left++;
    else right--;
  }

  cout << cnt;
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
