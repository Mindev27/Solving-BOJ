#include <iostream>

using namespace std;

int main() {
  string code;
  cin >> code;

  if(code == "fdsajkl;" || code == "jkl;fdsa")
    cout << "in-out";
  else if(code == "asdf;lkj" || code == ";lkjasdf")
    cout << "out-in";
  else if(code == "asdfjkl;")
    cout << "stairs";
  else if(code == ";lkjfdsa")
    cout << "reverse";
  else
    cout << "molu";
}