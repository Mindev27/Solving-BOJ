#include <iostream>

using namespace std;

int main() {
	int testCase, a, b;
	cin >> testCase;
	for(int t = 0; t < testCase; t++) {
		int result = 1;
    
		cin >> a >> b;
		if(b % 4 == 0) // b는 4사이클이 최대
      b = 4;
    else
      b = b % 4;
    
		for(int i = 0; i < b; i++)
      result *= a;
    
		if(result % 10 == 0)
      cout << 10 << "\n";
    else
      cout << result % 10 << "\n";
	}
}