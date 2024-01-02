#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int repeat = t.length() - s.length();

  // t에서 뒤부터 하나씩 빼면서 거꾸로 연산
  int endIdx = t.length() - 1;
  
  for(int i = 0; i < repeat; i++){
    
    if(t[endIdx] == 'B'){ // B라면 빼고 뒤집기
      t.erase(t.begin() + endIdx);
      reverse(t.begin(), t.end());
      endIdx--;
    }
      
    else{
      t.erase(t.begin() + endIdx);
      endIdx--;
    }
  }

  if(s == t)
    cout << 1;
  else
    cout << 0;
}