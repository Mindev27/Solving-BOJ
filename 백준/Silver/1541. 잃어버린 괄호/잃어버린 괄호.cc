#include <iostream>

using namespace std;

int main() {
  string input, number = "";
  cin >> input;
  
  int result = 0;
  bool isMinus = false;
  
  for(int i = 0; i < input.size(); i++){
    if(input[i] == '-' || input[i] == '+'){
      if(isMinus){
        result -= stoi(number);
        number = "";
      }
      else{
        result += stoi(number);
        number = "";
      }
      
    }
    else{
      number.push_back(input[i]);
    }
    
    if(input[i] == '-')
      isMinus = true;
  }
  
  if(isMinus)
    result -= stoi(number);
  
  else
    result += stoi(number);

  cout << result;
}