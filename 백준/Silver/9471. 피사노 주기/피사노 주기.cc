#include <iostream>

using namespace std;

int main() {
  int iTestCase, n, m, temp, cycle;
  const int MAX_RANGE = 500001;
  int f0 = 0;
  int f1 = 1;

  cin >> iTestCase;

  for(int i = 0; i < iTestCase; i++){
    cin >> n >> m;
    
    for(int j = 1; j <= MAX_RANGE; j++){
      temp = (f0 + f1) % m;
      f0 = f1;
      f1 = temp;

      if(f0 == 0 && f1 == 1){
        cycle = j;
        break;
      }
    }

    cout << i+1 << ' ' << cycle << "\n";
  }

}