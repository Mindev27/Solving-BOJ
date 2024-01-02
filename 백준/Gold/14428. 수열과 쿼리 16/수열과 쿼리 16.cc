/* 루트노드에는 전체수의 최솟값의 인덱스를 담음
그 아래로 그 범위에서 최솟값의 인덱스를 저장 */
#include <iostream>
#include <climits>

using namespace std;

int n, q;
int board[100005] = {};
int tree[400005] = {}; // 세그먼트 트리

// 더 작은 값의 인덱스를 반환
int minFunc(int a, int b){
  if(a == -1) return b;
  if(b == -1) return a;
  if(board[a] == board[b]){
    return min(a, b);
  }
  return board[a] > board[b] ? b : a;
}
// 세그 트리 초기화
int initSegtree(int start, int end, int node){
  if(start == end) return tree[node] = start;
  int mid = (start + end) / 2;
  return tree[node] = minFunc(initSegtree(start, mid, node * 2), initSegtree(mid + 1, end, node * 2 + 1));
}

// 세그트리 업데이트
int update(int start, int end, int node, int idx){
  if(start > idx || end < idx || start == end){
    return tree[node];
  }
  int mid = (start + end) / 2;
  return tree[node] = minFunc(update(start, mid, node * 2, idx), update(mid + 1, end, node * 2 + 1, idx));
}

// 쿼리에 대해 최솟값을 찾는 함수
int findQuery(int start, int end, int node, int left, int right) {
  if (right < start || end < left) return -1; // 범위 벗어남
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return minFunc(findQuery(start, mid, node * 2, left, right), findQuery(mid + 1, end, node * 2 + 1, left, right));
}


int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> board[i];
  }

  initSegtree(0, n - 1, 1);

  cin >> q;
  for(int i = 0; i < q; i++){
    int a, b, c; cin >> a >> b >> c;
    if(a == 2){ // 출력하는 경우
      cout << findQuery(0, n - 1, 1, b - 1, c - 1) + 1 << "\n";
    }
    else{ // 업데이트 하는 경우
      board[b - 1] = c;
      update(0, n - 1, 1, b - 1);
    }
  }
}