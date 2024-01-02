#include <iostream>
#include <queue>

using namespace std;

void BFS();

int main() {
  int n, m;
  int map[101] = {};
  int move[101] = {};
  int ladderSnake[30][2] = {};

  //map배열 초기화
  for(int i = 1; i <= 100; i++){
    map[i] = i;
    move[i] = -1;
  }

  cin >> n  >> m;
  int start, end;
  for(int i = 0; i < n + m; i++){
    int a, b;
    cin >> a >> b;
    ladderSnake[i][0] = a;
    ladderSnake[i][1] = b;
    map[a] = b;
  }

  move[1] = 0;
  
  queue<int> q;
  q.push(1);

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    for(int i = 1; i <= 6; i++){
      int next = cur + i;
      if(next <= 100){
        next = map[next];
        if(move[next] == -1){
          move[next] = move[cur] + 1;
          q.push(next);
        }
      }
    }
  }

  cout << move[100];
}