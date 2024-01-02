#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int commandNum;
  cin >> commandNum;

  for(int i = 0; i < commandNum; i++){
    string cmd;
    cin >> cmd;

    if(cmd == "push"){
      int a;
      cin >> a;
      q.push(a);
    }
      
    else if(cmd == "pop"){
      if(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
      }
      else
        cout << "-1\n";
    }
      
    else if(cmd == "size") cout <<  q.size() << "\n";
      
    else if(cmd == "empty")  cout << q.empty() << "\n";
      
    else if(cmd == "front"){
      if(!q.empty())
        cout << q.front() << "\n";
      else
        cout << "-1\n";
    }  
      
    else{
      if(!q.empty())
        cout << q.back() << "\n";
      else
        cout << "-1\n";
    } 
  }
}