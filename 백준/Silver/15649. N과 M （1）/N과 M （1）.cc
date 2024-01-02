#include <iostream>

#include <vector>

using namespace std;

int n, m;

vector<int> v;

bool visited[9];

void dfs(int len);

void printResult();

int main(){

  cin >> n >> m;

  

  dfs(0);

}

void dfs(int len){

  if(len == m){

    printResult();

    return;

  }

  

  for(int i = 1; i <= n; i++){

    if(visited[i] == false){

      visited[i] = true;

      v.push_back(i);

      dfs(len + 1);

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