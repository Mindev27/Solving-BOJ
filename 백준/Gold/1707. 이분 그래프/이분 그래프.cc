/*
  BFS로 구현
  첫 노드를 1로 색칠하고 인접한 노드를 확인하며 2로 색칠
  큐에서 꺼내면서 색깔을 확인하며 다른 색깔로 칠하기
  방문한 노드는 색만 체크
  모든 노드를 방문할 때 까지 반복
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool isCorrect;
int color[20001] = {};
vector<int> map[20001]; // 인접 리스트

void BFS(int x);

int main() {
  int testCase;
  cin >> testCase;

  while(testCase--){
    isCorrect = true;
    int vNum, eNum;
    cin >> vNum >> eNum;

    // 정보 초기화
    for(int i = 1; i <= vNum; i++){
      color[i] = 0;
      map[i].clear();
    }
    
    // 인접 리스트에 저장
    for(int i = 0; i < eNum; i++){
      int a, b;
      cin >> a >> b;
      map[a].push_back(b);
      map[b].push_back(a); 
    }

    //색칠하지 않고 틀리지 않았다면 탐색
    for(int i = 1; i <= vNum; i++){
      if(color[i] == 0 && isCorrect){
        BFS(i);
      }
    }

    if(isCorrect) 
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
}

void BFS(int x){
  queue<int> q;
  color[x] = 1; //처음 노드를 1로 칠하기
  q.push(x);
  
  while(!q.empty()){
    
    int curNode = q.front();
    int curColor = color[curNode];
    q.pop();
  
    //연결된 노드 탐색
    for(int j = 0; j < map[curNode].size(); j++){
      
      if(curColor == color[map[curNode][j]]){
        isCorrect = false;
      }

      //방문하지 않았다면 앞 노드와 다른 색으로 칠하기
      if(color[map[curNode][j]] == 0){
        if(curColor == 1) color[map[curNode][j]] = 2;
        if(curColor == 2) color[map[curNode][j]] = 1;
        q.push(map[curNode][j]);
      }
    }
  }
}