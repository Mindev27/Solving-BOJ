#include <iostream>

using namespace std;

long long int power(int base, int exponent);

int main() {
  int testCase;
  cin >> testCase;
  char c = cin.get();

  for(int t = 0; t < testCase; t++){
    string data;
    int tempBracket = 0;
    int maxBracket = 0;
    getline(cin, data);

    for(int i = 0; i < data.size(); i++){
      if(data[i] == '[')
        tempBracket++;
      else
        tempBracket--;

      maxBracket = max(maxBracket, tempBracket);
    }

    cout << power(2, maxBracket) << "\n";
  }
}

long long int power(int base, int exponent) {
  if(exponent == 0)
    return 1;
  else if(exponent == 1)
    return base;
  
  long long int half = power(base, exponent / 2);
  long long int result = (half * half);

  if (exponent % 2 == 1) {
    result = (result * base);
  }

  return result;
}