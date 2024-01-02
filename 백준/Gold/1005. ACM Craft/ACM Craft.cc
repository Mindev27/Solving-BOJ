#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> s; // 위상 정렬에서 답을 저장할 스택

//노드 구조체 정의
struct Node
{
  bool visited = false;
  int pointedCnt = 0; // 지목당한 횟수
  int buildTime; // 건설에 걸리는 시간
  vector<int> pointingNode; // 가리키는 노드
  vector<int> possibleTime; // 이전노드에서 받은 가능한 시간들
  int minTime; //건설에 걸리는 최소시간
};

//함수 원형 선언
void input(int towerNum, int infoPtr, Node **nodeArr);
void topologicalSort(Node **nodeArr, int towerNum);
void dfs(int k, Node **nodeArr);
void findAnswer(Node **nodeArr, int towerNum, int keyTower);

int main() {
  int testCase, towerNum, infoNum;

  cin >> testCase;

  for(int i = 0; i < testCase; i++){
    int keyTower;
    
    cin >> towerNum >> infoNum;

    Node **nodeArr = new Node * [towerNum + 1];
    for (int j = 0; j < towerNum + 1; j++) {
      nodeArr[j] = new Node;
    }

    for(int j = 1; j <= towerNum; j++){
      cin >> nodeArr[j] -> buildTime;
    }

    input(towerNum, infoNum, nodeArr); // 입력

    cin >> keyTower;
    
    topologicalSort(nodeArr, towerNum); // 위상정렬
    findAnswer(nodeArr, towerNum, keyTower); //bottom-up으로 최소시간 계산
  
    //동적 할당해제
    delete[] nodeArr;
  }
}

//입력 함수
void input(int towerNum, int infoPtr, Node **nodeArr) {
  // 키 정보 입력
  for (int i = 0; i < infoPtr; i++) {
    int tempA, tempB;
    cin >> tempA >> tempB;
    nodeArr[tempA] -> pointingNode.push_back(tempB);
    nodeArr[tempB] -> pointedCnt += 1;
  }
}

// DFS 탐색 함수
void dfs(int k, Node **nodeArr) {
  nodeArr[k]->visited = true;
  
  // 참조로 선언하여 복사하지 않도록 변경
  vector<int> &temp = nodeArr[k]->pointingNode; 

  for (int i = 0; i < temp.size(); i++) {
    int nextNode = temp[i]; // temp[i] 값을 nextNode로 가져옴
    if (!nodeArr[nextNode]->visited)
      dfs(nextNode, nodeArr); // 재귀적으로 탐색
  }

  s.push(k); // 탐색이 끝난 후 돌아오면서 push
}

// 위상 정렬
void topologicalSort(Node **nodeArr, int towerNum) {

  // 배열을 순회하며 0인 값을 탐색
  for (int i = 1; i <= towerNum; i++) {
    // 방문하지 않았다면 DFS 탐색
    if (!nodeArr[i]->visited)
      dfs(i, nodeArr); // dfs 함수 실행
  }
}

void findAnswer(Node **nodeArr, int towerNum, int keyTower) {
  while (!s.empty()) {
    int current = s.top();
    vector<int> &v = nodeArr[current]->possibleTime;

    if (nodeArr[current]->pointedCnt == 0) { // 초기노드이면
      nodeArr[current]->minTime = nodeArr[current]->buildTime;
    } else {
      nodeArr[current]->minTime = nodeArr[current]->buildTime + *max_element(v.begin(), v.end());
    }

    // 다음노드에 최소시간 값 넘겨주기
    vector<int> &temp = nodeArr[current]->pointingNode;

    int currentMinTime = nodeArr[current]->minTime;

    for (int i = 0; i < temp.size(); i++) {
      int nextNode = temp[i];
      
      nodeArr[nextNode]->possibleTime.push_back(currentMinTime);   
    }

    //만약 찾는 타워라면 break
    if (current == keyTower) {
      cout << nodeArr[keyTower]->minTime << "\n";
      break;
    }

    s.pop();
  }
}