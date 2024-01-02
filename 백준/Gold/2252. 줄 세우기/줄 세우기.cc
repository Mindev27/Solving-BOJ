#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> s; // 위상 정렬에서 답을 저장할 스택

//노드 구조체 정의
struct Node
{
  bool visited = false;
  vector<int> pointingNode;
  int pointedCnt = 0;
};

//함수 원형 선언
void input(int studentPtr, int infoPtr, Node **nodeArr);
void topologicalSort(Node **nodeArr, int studentNum);
void dfs(int k, Node **nodeArr);
void print_result();

int main() {
  int studentNum, infoNum;
  cin >> studentNum >> infoNum;

  Node **nodeArr = new Node * [studentNum + 1];
  for (int i = 0; i < studentNum + 1; i++) {
    nodeArr[i] = new Node;
  }
  
  input(studentNum, infoNum, nodeArr); // 입력
  topologicalSort(nodeArr, studentNum); // 위상정렬
  print_result(); //답 출력

  //동적 할당해제
  delete[] nodeArr;
}

//입력 함수
void input(int studentPtr, int infoPtr, Node **nodeArr) {
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
void topologicalSort(Node **nodeArr, int studentNum) {

  // 배열을 순회하며 0인 값을 탐색
  for (int i = 1; i <= studentNum; i++) {
    // 방문하지 않았다면 DFS 탐색
    if (!nodeArr[i]->visited)
      dfs(i, nodeArr); // dfs 함수 실행
  }
}

void print_result() {
  while(!s.empty()){
    int ans = s.top();
    s.pop();
    cout << ans << ' ';
  }
}