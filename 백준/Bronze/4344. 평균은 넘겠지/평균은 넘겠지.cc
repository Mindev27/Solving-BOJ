#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int testCase;
  cin >> testCase;

  for(int i = 0; i < testCase; i++){
    int stNum, sum = 0, data[1000] = {};
    cin >> stNum;
    
    for(int j = 0; j < stNum; j++){
      cin >> data[j];
      sum += data[j];
    }

    double avg = (double)sum / stNum;

    int bestSt = 0;
    for(int j = 0; j < stNum; j++){
      if(avg < data[j])
        bestSt++;
    }

    double percent =  (double)bestSt * 100 / stNum;
    printf("%.3lf%\n", percent);
  }
}
