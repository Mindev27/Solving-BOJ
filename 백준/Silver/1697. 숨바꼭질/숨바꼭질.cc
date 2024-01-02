#include <iostream>
#include <queue>

using namespace std;

const int SIZE =222222;
bool visited[SIZE] = {false};
queue<int> BFSqueue;
queue<int> subBFSqueue;


int BFS(int v, int m);
void subBFSpush(int k);

int BFS(int v, int m){ // 탐색 함수
  int time = 0;
  int current = v;
  
  if(current == m){ // 잡았다면 출력
    return time;
  }  

  BFSqueue.push(v); // v를 push하고
  visited[v] = true; // 방문했다고 표시

  //탐색
  while(true){ 
    time += 1; // 깊이 증가

    while(!BFSqueue.empty()){ // BFSqueue가 빌때까지 반복
      
      current = BFSqueue.front();
      BFSqueue.pop();

      // 찾았으면 종료
      if(current-1 == m || current+1 == m || current*2 == m) return time;
      
      if(current - 1 >= 0 && current - 1 < SIZE){ //범위 안이라면 
        subBFSpush(current - 1); // 큐에 push
      }
    
      if(current + 1 >= 0 && current + 1 < SIZE){
        subBFSpush(current + 1);
      }
        
      if(current * 2 >= 0 && current * 2 < SIZE){
        subBFSpush(current * 2);
      }
    }
  
    while(!subBFSqueue.empty()){ // subBFSqueue를 BFSqueue로 옮기기
      int temp = subBFSqueue.front();
      BFSqueue.push(temp);
      subBFSqueue.pop();
    }
  }

  return time;
}

//새로운 sub배열에 push하는 함
void subBFSpush(int k){
  if(!visited[k]){ // 방문하지 않았다면
    subBFSqueue.push(k); // 큐에 push
    visited[k] = true; // 방문함을 표시
  }
}

int main(){
  int n, m;
  
  cin >> n >> m;
    
  cout << BFS(n, m); // BFS 실행 
}