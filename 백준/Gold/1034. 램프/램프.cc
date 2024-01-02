#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
string board[55] = {};
vector<pair<string, int>> map;

// 입력
void input() {
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> board[i]; // 문자열 형태로 입력
  }
  cin >> k;
}

// 문자열을 map에 넣기
void addData(string data){
  for(int i = 0; i < map.size(); i++){
    if(map[i].first == data){           // 찾았다면 개수 추가
      map[i].second++;
      return;
    }
  }
  // 없다면 데이터 추가
  map.push_back({data, 1});
}

// 행을 검사하며 불을 켤수있는지 판별 후, map에 넣기
void solve() {
  for(int i = 0; i < n; i++){
    int zeroNum = 0;
    
    for(int j = 0; j < m; j++){
      if(board[i][j] - '0' == 0)
        zeroNum++;
    }

    if(zeroNum <= k && zeroNum % 2 == k % 2)
      addData(board[i]);
  }
}

void printAnswer() {
  int maxNum = 0;
  
  for(int i = 0; i < map.size(); i++){
    maxNum = max(maxNum, map[i].second);
  }

  cout << maxNum;
}

int main() {
  // (void)freopen("input.txt", "r", stdin); // 파일 읽기
  
  ios_base::sync_with_stdio(false); // fastio
  cin.tie(0); cout.tie(0);
  
  input(); // 입력
  solve(); // 풀기
  
  printAnswer();

  return 0;
}