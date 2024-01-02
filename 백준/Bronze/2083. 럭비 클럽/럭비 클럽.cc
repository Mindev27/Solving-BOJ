#include <iostream>

using namespace std;

int main() {
  while(true){
    string name;
    int age, weight;

    cin >> name >> age >> weight;

    if(name == "#") break;

    if(age > 17 || weight >= 80)
      cout << name << " Senior\n";
    else
      cout << name << " Junior\n";
  }
}