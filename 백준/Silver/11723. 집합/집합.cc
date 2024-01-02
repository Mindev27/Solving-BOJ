#include <iostream>
#include <bitset>

using namespace std;

// set STL 사용해도 시간초과
// 비트마스킹 활용

int main() {
  int m, comNum, bit = 0;
  string command;
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> command;
    if(command == "add"){
      cin >> comNum;
      bit = bit | (1 << comNum);
    }

    else if(command == "remove"){
      cin >> comNum;
      bit = bit & (~(1 << comNum));
    }

    else if(command == "check"){
      cin >> comNum;
      if(bit & (1 << comNum)) // 1이라면 있고 참
        cout << 1 << "\n";
      else
        cout << 0 << "\n"; 
    }

    else if(command == "toggle"){
      cin >> comNum;
      bit = bit ^ (1 << comNum);
    }

    else if(command == "all"){
      bit = (1 << 21) - 1;
    }

    else{ // empty인 경우
      bit = 0;
    }
  }
}