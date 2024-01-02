#include <iostream>

using namespace std;

int channel, brokenNum;
bool broken[10] = {};

void input() {
  cin >> channel;
  cin >> brokenNum;
  for(int i = 0; i < brokenNum; i++){
    int a; cin >> a;
    broken[a] = true;
  }
}

bool canInput(int n){
  string k = to_string(n);
  bool check = true;
  
  for(int i = 0; i < k.length(); i++){
    if(broken[k[i] - '0'])
      check = false;
  }

  return check;
}

void solve() {
  // 100에서 움직이는게 한계값
  int minDist = abs(channel - 100);
  
  for(int i = 0; i <= 1000000; i++){
    if(canInput(i)){ // 입력이 가능하다면
      int tempDist = abs(channel - i) + to_string(i).length();
      minDist = min(minDist, tempDist);
    }
  }

  cout << minDist;
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  solve();
}