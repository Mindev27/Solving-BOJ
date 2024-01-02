#include <iostream>
#include <regex>

using namespace std;

bool check(const string& code){

  regex re("(100+1+|01)+");

  return regex_match(code, re);
}

int main() {
  int T;

  // freopen("input.txt", "r", stdin);

  cin >> T;

  while(T--){
    string input;
    cin >> input;
    
    if(check(input))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}