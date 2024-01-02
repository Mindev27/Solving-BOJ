#include <iostream>

using namespace std;

int n;
int cube[10005][10] = {}; // i번째 큐브, j와 맞닿은 면
int link[7] = {0, 6, 4, 5, 2, 3, 1};

// AF, BD, CE 연결되어있음(1,6 / 2,4 / 3,5)
void input() {
  cin >> n; 
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= 6; j++) {
      cin >> cube[i][j];
    }
  }
}

// 반대쪽 면의 수를 구하는 함수
int findOther(int idx, int t){
  int result = 0;
  for(int k = 1; k <= 6; k++){ 
    if(t == cube[idx][k]){
      result = cube[idx][link[k]];
    }
  }
  return result;
}

// 주사위 번호와 윗면이 주어질때 옆면중 가장 큰수
int getBest(int idx, int a){
  bool num[10] = {};
  num[a] = true;                 // 윗면 배제
  num[findOther(idx, a)] = true; // 아랫면 배제

  int best = 0;
  for(int i = 1; i <= 6; i++){
    if(!num[i]) best = max(best, i);
  }

  return best;
}


// 윗면 6개 다 돌려보기
void solve() {
  int result = 0;

  for(int i = 1; i <= 6; i++){
    int temp = 0;
    int top = i;
    int bottom = findOther(1, top);

    temp += getBest(1, top);      // 첫번째 주사위에서 옆면 가져가기
    
    for(int j = 2; j <= n; j++){
      top = findOther(j, top);
      temp += getBest(j, top);
    }
    result = max(result, temp); // result 업데이트
  }
  cout << result;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}