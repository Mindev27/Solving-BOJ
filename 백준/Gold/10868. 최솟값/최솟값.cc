#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int SIZE = 400005;
int n, m;
int board[SIZE] = {};               // 입력받은 숫자들
int tree[SIZE] = {};                // 세그먼트 트리(first: 최소, second: 최대)
vector<pair<int, int>> query(SIZE); // 쿼리

void input() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++){ // 숫자 입력
    cin >> board[i];
  }

  for(int i = 0; i < m; i++){ // 쿼리 입력
    int a, b; cin >> a >> b;
    query[i] = {a, b};
  }
}

// 최솟값의 인덱스 반환 함수
int minFunc(int a, int b){
  if(a == -1) return b;
  if(b == -1) return a;
  if(board[a] == board[b]){
    return min(a, b);
  }
  return board[a] > board[b] ? b : a;
}

// 최댓값의 인덱스 반환 함수
int maxFunc(int a, int b){
  if(a == -1) return b;
  if(b == -1) return a;
  if(board[a] == board[b]){
    return max(a, b);
  }
  return board[a] > board[b] ? a : b;
}

// 세그 트리 초기화(최솟값)
int initMinSegtree(int start, int end, int node){
  if(start == end) return tree[node]= start;
  int mid = (start + end) / 2;
  return tree[node] = minFunc(initMinSegtree(start, mid, node * 2), 
                                     initMinSegtree(mid + 1, end, node * 2 + 1));
}

// 쿼리에 대해 최솟값을 찾는 함수
int findMinNumInQuery(int start, int end, int node, int left, int right) {
  if (right < start || end < left) return -1; // 범위 벗어남
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return minFunc(findMinNumInQuery(start, mid, node * 2, left, right), 
                  findMinNumInQuery(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  input();

  // 세그트리 초기화
  initMinSegtree(1, n, 1);

  for(int i = 0; i < m; i++){
    int a = query[i].first;
    int b = query[i].second;
    
    cout << board[findMinNumInQuery(1, n, 1, a, b)] << "\n";
  }

  return 0;
}
