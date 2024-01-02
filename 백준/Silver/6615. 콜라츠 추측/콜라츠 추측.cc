#include <iostream>
#include <map>

using namespace std;

int main() {
  while (true) {
    int A, B;
    cin >> A >> B;
  
    if (A == 0 && B == 0)
      break;

    map<long long, int> sequenceA;

    long long x = A;
    int index = 0;
    sequenceA.insert({x, index});
    while (x != 1) {
      if (x % 2 == 0)
        x = x / 2;
      else
        x = 3 * x + 1;
  
      index++;
      sequenceA.insert({x, index});
    }

    int steps = 0;
    x = B;
    while (sequenceA.find(x) == sequenceA.end()) {
      if (x % 2 == 0)
        x = x / 2;
      else
        x = 3 * x + 1;
      
      steps++;
    }

    int steps_A = sequenceA.find(x)->second;
    int steps_B = steps;

    cout << A << " needs " << steps_A << " steps, " << B << " needs " << steps_B << " steps, they meet at " << x << "\n";
  }
}
