#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int testCase;
  cin >> testCase;

  for(int t = 0; t < testCase; t++){
    cout << "Case #" << t+1 << ": ";

    int x, y, n = 0, sum = 0;
    cin >> x >> y;

    //총 이동해야 하는 거리
    int dist = abs(x) + abs(y);

    //가능한 n을 찾기
    while(sum < dist || sum % 2 != dist % 2){
      n += 1;
      sum += n;
    }

    stack<char> ans;

    //역순으로 빼가면서 찾기
    for(int i = n; i > 0; i--){
      if(abs(x) < abs(y)){
        if(y > 0){
          y -= i;
          ans.push('N');
        }
        else{
          y += i;
          ans.push('S');
        }
      }
      else{
        if(x > 0){
          x -= i;
          ans.push('E');
        }
        else{
          x += i;
          ans.push('W');
        }
      }
    }

    //답 출력
    while(!ans.empty()){
      char temp = ans.top();
      ans.pop();
      cout << temp;
    }
    cout << "\n";
  }
}