#include <iostream>
#include <sstream>
using namespace std;

int minKnightMoves(int x, int y) {
  
  x = abs(x);
  y = abs(y);
  if(x > y)
    swap(x, y);
  
  if(x == 1 && y == 1) return 2;
  if(x == 0 && y == 1) return 3;
  if(x == 2 && y == 2) return 4;

  //y= 2x 위에 존재한다면
  if( y >= 2 * x) 
    return (y + 1) / 2 + (y / 2 - x) % 2;

  //아래에 있다면
  else 
    return (x + y) / 3 + (x + y) % 3;
}

int main() {
  string input;
  while (getline(cin, input)) {
    
    if (input == "END") {
      break;
    }
        
    istringstream iss(input);
    int x, y;
    if (iss >> x >> y) {
      int minMoves = minKnightMoves(x, y);
      cout << minMoves << endl;
    }
  }  
  return 0;
}