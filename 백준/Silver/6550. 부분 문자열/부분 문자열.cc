#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string &s, string &t) {
  int index = 0;
  for (char i : t) {
    if (index == s.length())
      return true;
      
    if (s[index] == i)
      index++;
  }
  return index == s.length();
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s, t;
  while (cin >> s >> t) {
    if (isSubstring(s, t)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}