#include <iostream>
using namespace std;

int temp;

void make_swap(int &x, int &y){
  if(x > y){
    temp = x;
    x = y;
    y = temp;
  }
  
}

int main() {
  int a, b, c;
  
  cin >> a >> b >> c;

  make_swap(a, b);
  make_swap(b, c);
  make_swap(a, b);

  cout << a << " " << b << " " << c;
}