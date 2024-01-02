#include <iostream>
#include <stack>

using namespace std;

void solve(string str) {
  stack<char> s;
  for(int i = 0; i < str.length(); i++){
    // 우선순위가 가장높기 때문에 같은연산자 나올때까지 pop
    if(str[i] == '*' || str[i] == '/'){  
      while(!s.empty() && (s.top() == '*' || s.top() == '/')){
        cout << s.top();
        s.pop();
      }
      s.push(str[i]);
    }
    // 비거나 여는 괄호까지 빼기
    else if(str[i] == '+' || str[i] == '-'){ 
      while(!s.empty() && s.top() != '('){
        cout << s.top();
        s.pop();
      }
      s.push(str[i]);
    }
    // 다시 여는 괄호가 나올때까지 pop
    else if(str[i] == ')'){ 
      while(!s.empty() && s.top() != '('){
        cout << s.top();
        s.pop();
      }
      s.pop();
    }
    else if(str[i] == '('){
      s.push(str[i]);
    }
      
    else{ // 문자라면
      cout << str[i];
    }
  }

  // 끝난다면 스택에 남은 연산자들 pop
  while(!s.empty()){ 
    cout << s.top();
    s.pop();
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  
  string expression;
  cin >> expression;
  
  solve(expression);
}