#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  vector<int> v;

  //입력
  while(true){
    cin >> n;
    
    if(n == 0)
      break;
    
    v.push_back(n);
  }

  sort(v.begin(), v.end());

  bool is_find = false;
  
  for(int i = 0; i < v.size() - 2; i++){
    if(v[i] + v[i + 1] > v[i + 2] && !is_find){
      cout << v[i] << ' ' << v[i + 1] << ' ' << v[i + 2];
      is_find = true;
    }
  }

  if(!is_find)
    cout << "NIE";
}