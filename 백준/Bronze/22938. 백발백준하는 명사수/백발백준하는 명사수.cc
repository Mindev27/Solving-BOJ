#include <iostream>

using namespace std;

int main() {
  long long x1, y1, r1, x2, y2, r2;

  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  long long int slide_sqare = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

  if(slide_sqare < (r1 + r2) * (r1 + r2))
    cout << "YES";
  else
    cout << "NO";
}