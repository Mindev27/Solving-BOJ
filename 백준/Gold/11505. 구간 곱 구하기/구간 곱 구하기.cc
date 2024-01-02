#include <climits>
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const int DIV = 1'000'000'007;
const int SIZE = 4000005;
int n, m, k;
int board[SIZE] = {}; // 입력받은 숫자들
ll tree[SIZE] = {};   // 세그먼트 트리
vector<pair<int, pair<int, int>>> query; // 쿼리

void input() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) { // 숫자 입력
    cin >> board[i];
  }

  for (int i = 0; i < m + k; i++) { // 쿼리 입력
    int a, b, c;
    cin >> a >> b >> c;
    query.push_back({a, {b, c}});
  }
}

// 세그 트리 초기화(최솟값)
ll initMulSegtree(int start, int end, int node) {
  if (start == end)
    return tree[node] = board[start];
  int mid = (start + end) / 2;
  return tree[node] = (initMulSegtree(start, mid, node * 2) *
                       initMulSegtree(mid + 1, end, node * 2 + 1)) % DIV;
}

// 쿼리에 대해 곱을 찾는 함수
ll findMulNumInQuery(int start, int end, int node, int left, int right) {
  if (right < start || end < left) return 1; // 곱이기 때문에 1을 곱해줌
  if (left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return (findMulNumInQuery(start, mid, node * 2, left, right) *
            findMulNumInQuery(mid + 1, end, node * 2 + 1, left, right)) % DIV;
}

// 값을 바꾸는 함수
void update(int start, int end, int node, int index, ll value){
  if(index < start || end < index) return; // 범위 벗어남

  if(start == end) tree[node] = value;
  else{
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, value);
    update(mid + 1, end, node * 2 + 1, index, value);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % DIV;
  }
}
int main() {
  //freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  input();

  // 세그트리 초기화
  initMulSegtree(1, n, 1);

  for (int i = 0; i < m + k; i++) {
    int command = query[i].first;
    ll a = query[i].second.first;
    ll b = query[i].second.second;

    if(command == 1)
      update(1, n, 1, a, b);
    else
      cout << findMulNumInQuery(1, n, 1, a, b) << "\n";
    
  }

  return 0;
}