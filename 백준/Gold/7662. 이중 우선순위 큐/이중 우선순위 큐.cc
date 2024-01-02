#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
  
  bool check[1000000] = {};
  
  int testCase;
  cin >> testCase;

  for(int t = 0; t < testCase; t++){
    int k;
    cin >> k;

    memset(check, false, sizeof(check));
    priority_queue<pair<int, int>> max_q; // 최대 힙
    priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> min_q; // 최소 힙

    for(int i = 0; i < k; i++){
      char command;
      int num;
      cin >> command >> num;
      
      // 삽입
      if(command == 'I'){ 
        max_q.push({num, i});
        min_q.push({num, i});
        check[i] = true;
      }

      // 삭제
      else{
        if(num == -1){ // 최솟값 삭제
          while(!min_q.empty()){ // 삭제했던 값들 없애기
            int idx = min_q.top().second;
            if(check[idx]) break; // 삭제했었다면 끝
            
            min_q.pop(); // 삭제하지 않았다면 삭제
          }

          if(!min_q.empty()){ // 비어있지 않다면 값 삭제
            check[min_q.top().second] = false;
            min_q.pop();
          }
        }

        else{ // 최대값 삭제
          while(!max_q.empty()){ // 삭제했던 값들 없애기
            int idx = max_q.top().second;
            if(check[idx]) break; // 삭제했었다면 끝
            
            max_q.pop(); // 삭제하지 않았다면 삭제
          }

          if(!max_q.empty()){ // 비어있지 않다면 값 삭제
            check[max_q.top().second] = false;
            max_q.pop();
          }
        }
      }
    }

    while(!max_q.empty()){ // 마지막으로 삭제했던 값들 없애기
      int idx = max_q.top().second;
      if(check[idx]) break; // 삭제했었다면 끝
      
      max_q.pop(); // 삭제하지 않았다면 삭제
    }
    
    while(!min_q.empty()){ // 마지막으로 삭제했던 값들 없애기
      int idx = min_q.top().second;
      if(check[idx]) break; // 삭제했었다면 끝
      
      min_q.pop(); // 삭제하지 않았다면 삭제
    }

    //출력
    if(min_q.empty()) cout << "EMPTY\n";
    else{
      cout << max_q.top().first << ' ' << min_q.top().first << "\n";
    }
  }
}