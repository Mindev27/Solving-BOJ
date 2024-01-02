#include <iostream>

using namespace std;

int main() {
  int num; 
  cin >> num;

  if(num % 10 == num / 10)
    cout << "1";
  else
    cout << "0";
}