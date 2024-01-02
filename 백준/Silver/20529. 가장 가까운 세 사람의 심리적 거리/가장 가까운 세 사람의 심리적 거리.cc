#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int testCase;
  cin >> testCase;

  while(testCase--){
    vector<string> v;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
      string input; cin >> input;
      v.push_back(input);
    }

    if(n > 32) // 32이상이면 무조건 3개가 동일함
      cout << 0 << "\n";
      
    else{ // 아니면 완전 탐색
      int result = 999;
      
      for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
          for(int k = j + 1; k < n; k++){
            
            int tempResult = 0;
            
            // i와 j의 거리 계산
            int distIJ = 0;
            for(int s = 0; s < 4; s++){
              if(v[i][s] != v[j][s])
                distIJ++;
            }
            tempResult += distIJ;

            // j와 k의 거리 계산
            int distJK = 0;
            for(int s = 0; s < 4; s++){
              if(v[j][s] != v[k][s])
                distJK++;
            }
            tempResult += distJK;

            // k와 i의 거리 계산
            int distKI = 0;
            for(int s = 0; s < 4; s++){
              if(v[k][s] != v[i][s])
                distKI++;
            }
            tempResult += distKI;

            result = min(result, tempResult);
          }
        }
      }

      cout << result << "\n";
    }
  }
}