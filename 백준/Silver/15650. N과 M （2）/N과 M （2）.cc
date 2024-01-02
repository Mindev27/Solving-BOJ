#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> v;
bool visited[9] = {};

void dfs(int len, int start);
void printResult();

int main(){
  cin >> n >> m;
  
  dfs(0, 1);
}

void dfs(int len, int start){
  if(len == m){
    printResult();
    return;
  }

  for(int i = start; i <= n; i++){
    if(visited[i] == false){
      visited[i] = true;
      v.push_back(i);
      dfs(len + 1, i);
      v.pop_back();
      visited[i] = false;
    }
  }
}

void printResult(){
  for(int i = 0; i < m; i++){
    cout << v[i] << ' ';
  }
  cout << "\n";
}