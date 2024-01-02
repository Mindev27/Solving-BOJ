#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int number[4] = {};
bool visited[10000] = {};

string BFS(int s, int e);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int testCase;
  cin >> testCase;

  for(int i = 0; i < testCase; i++){
    memset(visited, false, sizeof(visited));
    int start, end;
    cin >> start >> end;
    cout << BFS(start, end) << "\n";
  }
}

string BFS(int s, int e) {
  queue<pair<int, string>> q;

  visited[s] = true; // 처음숫자 방문표시
  q.push({s,""});

  while(!q.empty()){
    int num = q.front().first;
    string move = q.front().second;
    q.pop();

    //찾았다면 출력
    if(num == e) return move;
    
    int nextNum;
    string newMove;
    
    // D
    nextNum = num * 2;
    if(nextNum >= 10000) nextNum -= 10000;
    if(!visited[nextNum]){
      visited[nextNum] = true;
      newMove = move + 'D';
      q.push({nextNum, newMove});
    }
    
    // S
    nextNum = num - 1;
    if(nextNum < 0) nextNum = 9999;
    if(!visited[nextNum]){
      visited[nextNum] = true;
      newMove = move + 'S';
      q.push({nextNum, newMove});
    }

    // L
    nextNum = (num % 1000) * 10 + (num / 1000);
    if(!visited[nextNum]){
      visited[nextNum] = true;
      newMove = move + 'L';
      q.push({nextNum, newMove});
    }

    // R
    nextNum = (num / 10) + (num % 10) * 1000;
    if(!visited[nextNum]){
      visited[nextNum] = true;
      newMove = move + 'R';
      q.push({nextNum, newMove});
    }
  }
}
