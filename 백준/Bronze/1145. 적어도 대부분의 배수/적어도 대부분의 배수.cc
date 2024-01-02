#include <iostream>

using namespace std;

int nums[5] = {};

void input() {
  for(int i = 0; i < 5; i++){
    cin >> nums[i];
  }
}

void solve() {
  for(int i = 1; i < 10000000; i++){
    int cnt = 0;
    for(int j = 0; j < 5; j++){
      if(i % nums[j] == 0)
        cnt++;
    }
    if(cnt >= 3){
      cout << i;
      return;
    }
  }
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
