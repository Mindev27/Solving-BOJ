#include <iostream>

using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int temp; cin >> temp;
    if(temp == 300) 
      cout << "1 ";
    else if(temp >= 275)
      cout << "2 ";
    else if(temp >= 250)
      cout << "3 ";
    else
      cout << "4 ";
  }
}
