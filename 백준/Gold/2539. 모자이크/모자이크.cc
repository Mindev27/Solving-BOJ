#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int row, col, paperNum, wrongNum, maxHeight = 1;
vector<int> v;

void input() {
  cin >> row >> col;
  cin >> paperNum >> wrongNum;
  for (int i = 0; i < wrongNum; i++) {
    int a, b; cin >> a >> b;
    v.push_back(b);
    maxHeight = max(maxHeight, a);
  }
}

void solve() {
  sort(v.begin(), v.end());
  
  int s = maxHeight, e = v.back();
  
  for(int i = s; i <= e; i++){
    int erasedNum = 1;
    int curX = v[0];
    for(int j = 1; j < wrongNum; j++) {
      if(v[j] - curX >= i) {
        erasedNum += 1;
        curX = v[j];
      }
    }
    if(erasedNum <= paperNum){
      cout << i; return;
    }
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}