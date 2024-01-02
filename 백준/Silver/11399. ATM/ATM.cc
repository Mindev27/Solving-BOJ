#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int iTestcase, iResult, time[1000] = {};
  cin >> iTestcase;

  for(int i  = 0; i < iTestcase; i++){
    cin >> time[i];
  }
  
  sort(time, time + iTestcase);

  iResult = 0;
  for(int i  = 0; i < iTestcase; i++){
    iResult += time[i] * (iTestcase - i);
  }

  cout << iResult;
}