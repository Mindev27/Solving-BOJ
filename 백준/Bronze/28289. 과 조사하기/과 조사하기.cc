#include <iostream>

using namespace std;

int main() {
  int stNum;
  cin >> stNum;

  int sw = 0 ,em = 0, ai = 0, no = 0;
  for(int i = 0; i < stNum; i++){
    int a, b, c;
    cin >> a >> b >> c;

    if(a == 1)
      no++;
    else{
      if(b == 1 || b == 2) sw++;
      if(b == 3) em++;
      if(b == 4) ai++;
    }
  }

  cout << sw << "\n";
  cout << em << "\n";
  cout << ai << "\n";
  cout << no << "\n";
}