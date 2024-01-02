#include <iostream>

using namespace std;

int chef[5] = {};

void input() {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 4; j++){
      int a; cin >> a;
      chef[i] += a;
    }
  }
}

void solve() {
  int idx = 1;
  int maxScore = 0;
  for(int i = 0; i < 5; i++){
    if(maxScore < chef[i]){
      idx = i + 1;
      maxScore = chef[i];
    }
  }
  cout << idx << ' ' << maxScore << '\n';
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}