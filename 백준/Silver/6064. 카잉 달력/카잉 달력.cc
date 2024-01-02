#include <iostream>

using namespace std;

int gcd(int a, int b);

int main() {
  int testCase;
  cin >> testCase;

  for(int t = 0; t < testCase; t++){
    bool isCorrect = false;
    int month, day, x, y, end;
    cin >> month >> day >> x >> y;

    end = month * day;
    
    for (int i = x - 1; i < end; i += month){
  		if (i % day == y - 1){
        cout << i + 1<< "\n";
        isCorrect = true;
        break;
      }
  	}
    
  	if (!isCorrect) 
      cout << -1 << "\n";
  }
}

int gcd(int a, int b){ 
    if(b == 0){
      return a;
    }else{
      return gcd(b, a % b);
    }
}
