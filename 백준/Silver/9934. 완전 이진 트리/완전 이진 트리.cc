#include <iostream>
#include <vector>

using namespace std;

int k;
int paper[1050] = {};
vector<int> binaryTree[11];

void input(){
  cin >> k;

  for(int i = 0; i < (1 << k) - 1; i++){
    cin >> paper[i];
  }
}

void inorder(int start, int end, int depth){
  if(start == end) return;

  int mid = (start + end) / 2;

  binaryTree[depth].push_back(paper[mid]);

  inorder(start, mid, depth + 1);
  inorder(mid + 1, end, depth + 1);
}

void printAnswer(){
  
  for(int i = 0; i < k; i++){
    for(int j = 0; j < binaryTree[i].size(); j++){
      cout << binaryTree[i][j] << ' ';
    }
    cout << "\n";
  }
}

int main() {
   // freopen("input.txt", "r", stdin);
  
  input();

  int limit = (1 << k) - 1; // 이진트리에서 노드의 개수
  inorder(0, limit, 0);

  printAnswer();
}