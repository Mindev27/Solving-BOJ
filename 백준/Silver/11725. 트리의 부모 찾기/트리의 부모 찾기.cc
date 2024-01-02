#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  const int MAX = 100001;
  vector<int> linked[MAX];
  int ans[MAX] = {};
  bool visited[MAX] = {};
  int n;
  cin >> n;

  // 인접 리스트 구현
  for(int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    linked[a].push_back(b);
    linked[b].push_back(a);
  }

  queue<int> q;
  q.push(1);
  visited[1] = true;

  while(!q.empty()){
    int x = q.front();
    visited[x] = true;
    q.pop();
    
    for(int i = 0; i < linked[x].size(); i++){
      int next = linked[x][i];
      if(visited[next])
        ans[x] = next;
      else{
        q.push(next);
      }        
    }
  }

  for(int i = 2; i <= n; i++){
    cout << ans[i] << "\n";
  }
}