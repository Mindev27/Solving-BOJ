#include <iostream>

using namespace std;

int N, S;
int arr[100005];

void input() {
  cin >> N >> S;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
}

void solve() {
  int left = 0, right = 0, sum = 0, result = N + 1;
  while(left <= right){
    if(sum >= S){
      result = min(result, right - left);
      sum -= arr[left++];
    }
    else if(right == N) break;
    else sum += arr[right++];
  }

  if(result == N + 1) cout << 0;
  else cout << result;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}