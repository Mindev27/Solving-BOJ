#include <iostream>

using namespace std;

int main() {
  bool visited[50001] = {};
  int num[50001]= {};
  int n;
  cin >> n;

  // 입력
  for(int i = 1; i <= n; i++)
    cin >> num[i];

  /*
  앞에서부터 확인하며, 숫자 - 1이 0이 아니고 방문하지 않을 때
  숫자 - 1를 탐색. 두 값을 바꾸고 방문표시 O(N^2)
  */
  
  for(int i = 1; i <= n; i++){
    int now = num[i];
    visited[now] = true;

    if(now == 1) continue; // 0은 없기 때문에 pass

    int changeNum = now - 1; // 바꿀 숫자
    if(!visited[changeNum]){ // 방문하지 않았을 때    
      for(int idx = i + 1; idx <= n; idx++){ // 숫자 - 1 찾기
        if(num[idx] == changeNum){
          swap(num[i], num[idx]); // 바꾸기
          visited[changeNum] = true;
        }
      }
    }
  }

  for(int i = 1; i <= n; i++)
    cout << num[i] << ' ';
}