#include <iostream>
#include <queue>

using namespace std;

int n, change;
int arr[55] = {};

void swap(int a, int b){
  for(int i = b; i > a; i--){
    int temp = arr[i - 1];
    arr[i - 1] = arr[i];
    arr[i] = temp;
  }
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> change;
}

void solve() {
  for(int start = 0; start < n; start++){
    int curMax = arr[start], maxIdx = start;
    
    for(int i = start + 1; i < n; i++){
      if(i - start <= change && arr[i] > curMax){
        curMax = arr[i];
        maxIdx = i;
      }
    }
    change -= maxIdx - start;
    swap(start, maxIdx);
    
    // 내림차순으로 정렬 또는 더 이상 횟수가 없다면 끝
    if(change <= 0) break;
  }

  for(int i = 0; i < n; i++)
    cout << arr[i] << ' ';
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
