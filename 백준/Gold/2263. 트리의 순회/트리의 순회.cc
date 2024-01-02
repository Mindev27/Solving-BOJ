#include <iostream>
#include <map>

using namespace std;

const int SIZE = 100005;
int n;
int in[SIZE];
int po[SIZE];
map<int, pair<int, int>> tree;

void input() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> in[i];
  for(int i = 0; i < n; ++i)
    cin >> po[i];
}

// 후위순회의 끝 값이 root노드,
// 중위순회에서 root 찾고 분할탐색
void makeTree(int root, int inS, int inE, int poS, int poE) {
  int inRoot = 0; // 후위순회의 루트위치
  // 중위순회에서 root 찾기
  for(int i = inS; i <= inE; ++i){
    if(in[i] == root){
      inRoot = i;
      break;
    }
  }

  int leftLen = inRoot - inS; // 왼쪽 서브트리 길이

  // 왼쪽 오른쪽 노드 설정
  int leftNode = (leftLen > 0) ? po[poS + leftLen - 1] : 0;
  int rightNode = (inRoot < inE) ? po[poE - 1] : 0;

  tree[root] = {leftNode, rightNode};

  if (leftLen > 0)
    makeTree(leftNode, inS, inRoot - 1, poS, poS + leftLen - 1);
  if (inRoot < inE)
    makeTree(rightNode, inRoot + 1, inE, poS + leftLen, poE - 1);
  }


// 프리오더 출력
void printPreorder(int root) {
  if (root == 0) return;
  cout << root << " "; 
  printPreorder(tree[root].first);
  printPreorder(tree[root].second);
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  makeTree(po[n - 1], 0, n - 1, 0, n - 1);
  printPreorder(po[n - 1]);
  
  return 0;
}
