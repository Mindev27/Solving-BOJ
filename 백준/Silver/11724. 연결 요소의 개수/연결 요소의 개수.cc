#include <iostream>
#include <stack>

using namespace std;

const int SIZE = 1001;
int node, line, u, v;
stack<int> s;
int map[SIZE][SIZE] = {0,};
bool visited[SIZE] = {false,};

void dfs(int k);

int main() {
  int union_num = 0;
  
  cin >> node >> line;

  for(int i = 0; i < line; i++){
    cin >> u >> v;
    map[u][v] = 1;
    map[v][u] = 1;
  }
  
  for(int i = 1; i <= node; i++){
    if(!visited[i]){
      union_num++;
      dfs(i);
    } 
  }

  cout << union_num;
}

void dfs(int k){
  s.push(k);

  while(!s.empty()){
    int temp = s.top();
    s.pop();

    if(!visited[temp]){
      visited[temp] = true;
      
      for(int i = 1; i <= node; i++){
        if(map[temp][i] == 1 && !visited[i])
          s.push(i);
      }
    }
    
  }
}