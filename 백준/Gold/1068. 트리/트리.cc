#include <iostream>
#include <vector>

using namespace std;

int n, key, root, leafNum = 0;
vector<int> trees[50]; // 자식노드를 저장

void input(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a == -1){ // 루트노드면 저장
      root = i;
    }
    else trees[a].push_back(i); // 트리의 자식으로 push
  }
  cin >> key; // 지울 노드
}

// 리프노드의 개수를 찾는 함수
bool findLeaf(int Node){
  if(Node == key) return false; // 만약 부모가 죽은 노드
  
  if(trees[Node].size() == 0){ // 리프노드이면 개수 +1
    leafNum++;
    return 1;
  }
  
  for(int i = 0; i < trees[Node].size(); i++){
    bool cnt = findLeaf(trees[Node][i]);
    if(!cnt && trees[Node].size() == 1)
      leafNum++;
  }
  
  return true;
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  input();

  findLeaf(root); // 리프노드 개수 찾기

  cout << leafNum;
}