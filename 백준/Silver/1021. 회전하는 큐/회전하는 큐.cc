#include <iostream>

#include <queue>

using namespace std;

int main() {

  int n, m, key, move = 0;

  queue<int> q;

  

  cin >> n >> m;

  for(int i = 1; i <= n; i++){

    q.push(i);

  }

  

  for(int i = 0; i < m; i++){

    cin >> key;

    int temp = q.front();

    int cnt = 0;

    while(key != temp){

      q.pop();

      q.push(temp);

      temp = q.front();

      cnt++;

    }

    q.pop();

    

    if(cnt < q.size() - cnt + 1) 

      move += cnt;

    else 

      move += q.size() - cnt + 1;

  }

  

  cout << move;

}