#include <iostream>
#include <stack>

using namespace std;

int main() {
  int testCase;
  cin >> testCase;

  while(testCase--){
    stack<int> s;
    int n; 
    cin >> n;

    for(int i = 0; i < n; i++){
      int input;
      cin >> input;
      s.push(input);
    }

    long long int result = 0;
    int maxNum = s.top();
    
    while(!s.empty()){
      int cur = s.top();
      s.pop();

      if(cur < maxNum)
        result += maxNum - cur;
      else
        maxNum = cur;
    }

    cout << result << "\n";
  }
}