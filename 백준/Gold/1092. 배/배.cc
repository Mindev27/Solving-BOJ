#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int craneNum, boxNum, maxCrane = 0;
int crane[50] = {};
vector<int> box;

void input();
int solve();

void input() {
  cin >> craneNum;
  for(int i = 0; i < craneNum; i++){
    cin >> crane[i];
  }

  cin >> boxNum;
  for(int i = 0; i < boxNum; i++){
    int a; cin >> a;
    box.push_back(a);
  }
}

int solve() {
  int time = 0; // 흐른 시간
  
  while(!box.empty()){
    time++;
    
    // 무게를 들 수 있다면 무거운것부터 그리디하게 들고가기
    for(int craneIdx = 0; craneIdx < craneNum; craneIdx++) {
      
      for(int boxIdx = 0; boxIdx < box.size(); boxIdx++){
        if(box[boxIdx] <= crane[craneIdx]){
          box.erase(box.begin() + boxIdx);
          break;
        }
      }
    }
  }

  return time;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();

  // 둘다 내림차순 정렬
  sort(crane, crane + craneNum, greater<int>());
  sort(box.begin(), box.end(), greater<int>());

 // 최대값을 비교 후 불가능하다면 -1출력
  if(crane[0] < box[0]){
    cout << -1;
    return 0;
  }
  else{
    cout << solve();
  }
}