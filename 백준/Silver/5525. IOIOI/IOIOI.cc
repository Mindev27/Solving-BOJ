#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  cin >> m;

  string word;
  cin >>word;

  int count = 0;
  int level = 0; // IOI가 몇번 반복되는지 세는 변수
  
  for(int i = 0; i < m; i++){
    if(word[i] == 'I'){ // 첫 글자가 I일때
      while(word[i + 1] == 'O' && word[i + 2] == 'I'){ // IOI가 완성되면
        level++; // 반복횟수 +1

        if(level == n){
          count++;
          level -= 1;
        }
        i += 2; // 다음 두개를 판별하도록 +2
      }
    }
    level = 0; // 다시 초기화
  }

  cout << count;
}