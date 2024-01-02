/*
  B에서의 누적값을 저장 후
  dp[t] = a (B에서 t시간만큼을 덜 일할때 A가 일한 시간 a)
  로 정보를 저장.
  B가 일한시간은 B누적값 - t
  B누적값 - t와 dp[t] 중에 작은 값이 답
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int INF = 999999;
  vector<pair<int, int>> v;
  int dp[63001] = {}; // 251 * 251 크기의배열

  //dp배열 초기화
  dp[0] = 0;
  for(int i = 1; i <= 63000; i++){
    dp[i] = INF;
  }
  
  int n, result;
  cin >> n;

  int sumB = 0; // B누적값
  
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    sumB += b;

    // dp배열 업데이트
    // 여러번 계산되는 것을 피하기위해 역순으로 계산
    for(int j = 63000; j >= 0; j--){
      if(j - b >= 0){          // 범위 내의 값이며
        if(dp[j - b] != INF){ // 이전 값이 존재한다면
          dp[j] = min(dp[j - b] + a, dp[j]);
        }
      }
    }

    //순회하면서 최솟값 탐색
    result = INF;
    for(int i = 0; i <= 63000; i++){
      if(dp[i] != INF)
        result = min(result, max(sumB - i, dp[i]));
    }
  }

  cout << result;
}