#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int n, data[300001] = {}, iRealCut, iSum, iStart, iEnd;
  float dCutData, dAvg, dLevel;

  cin >> n;

  //0이라면 난이도 없음
  if(n == 0){
    cout << "0";
    return 0;
  } 

  for(int i = 0; i < n; i++){
    cin >> data[i];
  }

  //데이터 정렬
  sort(data, data + n);

  dCutData = (float)n * 0.15; // 15% 절삭

  iRealCut = round(dCutData); // 반올림
  iStart = iRealCut;
  iEnd = n - iRealCut;

  iSum = 0;
  for(int i = iStart; i < iEnd; i++){
    iSum += data[i];
  }

  dAvg = (float)iSum / (iEnd - iStart);

  dLevel = round(dAvg);

  cout << dLevel;
}