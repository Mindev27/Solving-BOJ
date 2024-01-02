#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main() {
  int testCase;
  cin >> testCase;
  
  for(int t = 0; t < testCase; t++){
    string command;
    cin >> command;

    int length;
    string input, temp;
    deque<int> dq;
    
    cin >> length;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
      if (isdigit(input[i])) { // 정수면 문자열에 추가
        temp += input[i];
      }
        
      else { // 정수가 아닌 글자가 올때
        if (!temp.empty()) { // 값이 있다면
          dq.push_back(stoi(temp)); // 정수로 바꿔서 넣기
          temp = ""; // temp 초기화
        }
      }
    }
    // R이 나오면 배열을 뒤집지 않고 덱에서 거꾸로 연산을 해준다
    bool isReverse = false, isError = false; 

    for (auto cmd : command){
      if(cmd == 'R')
        isReverse = !isReverse;
      else{
        if(!isReverse){ // 뒤집지 않았다면
          if(dq.empty()){ // 비어있다면 에러 출력
            cout << "error" << "\n";
            isError = true;
            break;
          }
          else // 뒤집지 않았기 때문에 pop_front
            dq.pop_front();
        }
        else{ // 뒤집었다면
          if(dq.empty()){ // 비어있다면 에러 출력
            cout << "error" << "\n";
            isError = true;
            break;
          }
          else // 뒤집었기 때문에 pop_back
            dq.pop_back();
        }
      }
    }

    if(!isError){
      cout << '[';
    }
    
    if(!isReverse && !dq.empty()){
      for(auto i = dq.begin(); i != dq.end() - 1; i++){
        cout << *i << ',';
      }
      cout << *(dq.end() - 1);
    }
    else if(isReverse && !dq.empty()){
      for(auto i = dq.rbegin(); i != dq.rend() - 1; i++){
        cout << *i << ',';
      }
      cout << *(dq.rend() - 1);
    }
    
    if(!isError){
      cout << "]\n";
    }
  }
}