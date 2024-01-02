#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n, k, i, cnt, input, max, index;
  string str, s;
  vector<int> number(500001);
  stack<int> stack, output;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n >> k;
  cin >> str;

  for(i = 0; i < n; i++){
    s = str[i];
    number[i] = stoi(s);
  }

  // 첫번째 숫자를 스택에 push
  stack.push(number[0]);
  index = 1;
  cnt = k;
  
  while(1){
    //cnt가 0이면 나머지 넣고 break
    if(cnt == 0){
      while(index <= n-1){
        stack.push(number[index]);
        index++;
      }
      break;
    }
      
    //숫자를 다 넣었는데 cnt 가 0이 아니라면 
    if(index == n && cnt != 0){
      //뒤에서부터 cnt 만큼 pop
      for(int j = 0; j < cnt; j++){
        stack.pop();
      }
      break;
    }
    
    //스택이 비었다면 push
    if(stack.empty()){

      stack.push(number[index]);
      index++;
    }
    //들어있는 숫자가 더 작으면 pop
    else if(stack.top() < number[index]){
      stack.pop();
      cnt--;
    }
    //들어있는 숫자가 더 크거나 같으면 push
    else if(stack.top() >= number[index]){
      stack.push(number[index]);
      index++;
    }
  }

  while(!stack.empty()){
    output.push(stack.top());
    stack.pop();
  }

  while(!output.empty()){
    cout << output.top();
    output.pop();
  }
}