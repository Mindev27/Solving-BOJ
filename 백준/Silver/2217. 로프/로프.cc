#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, rope[100000];
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> rope[i];
  }

  sort(rope, rope + n, greater<int>());

  int max = rope[0];
  for(int i = 1; i < n; i++){
    if(rope[i] * (i + 1) > max)
      max = rope[i] * (i + 1);
  }

  cout << max;
}