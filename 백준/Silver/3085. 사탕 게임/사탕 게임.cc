#include <iostream>
#include <algorithm>

using namespace std;

int count(int size, char map[][50]);

int main() {
  int n;
  char map[50][50] = {};
  cin >> n;

  //입력
  for(int i = 0; i < n; i++){
    string a; cin >> a;
    for(int j = 0; j < n; j++){
      map[i][j] = a[j];
    }
  }

  // //check
  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < n; j++){
  //     cout << map[i][j] << ' ';
  //   }
  //   cout << "\n";
  // }

  int result = 0;

  //행에서 바꾸며 최대길이 계산
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - 1; j++){

      if(map[i][j] != map[i][j + 1]){
        swap(map[i][j], map[i][j + 1]); // 행의 두 값을 바꾸고
        result = max(result, count(n, map)); // 최댓값 업데이트
        swap(map[i][j], map[i][j + 1]); // 원상복구
      }
    }
  }

  //열에서 바꾸며 최대길이 계산
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n; j++){

      if(map[i][j] != map[i + 1][j]){
        swap(map[i][j], map[i + 1][j]); // 행의 두 값을 바꾸고
        result = max(result, count(n, map));  // 최댓값 업데이트
        swap(map[i][j], map[i + 1][j]); // 원상복구
      }
    }
  }

  cout << result;
}

int count(int size, char map[][50]){
  int maxResult = 0;

  //행에서 탐색
  for(int i = 0; i < size; i++){
    char key = map[i][0]; // 초기 비교값 설정
    int rowMax = 1; // 한 행에서 최댓값
    
    for(int j = 1; j < size; j++){
      if(key == map[i][j]) // 다음값과 같다면 +1
        rowMax++;
        
      else{ // 다르다면 값 업데이트 후 나머지값 초기화
        maxResult = max(maxResult, rowMax);
        rowMax = 1;
        key = map[i][j];
      }
    }
    maxResult = max(maxResult, rowMax); // 행이 끝나면 업데이트
  }

  //열에서 탐색
  for(int j = 0; j < size; j++){
    char key = map[0][j]; // 초기 비교값 설정
    int colMax = 1; // 한 열에서 최댓값
    
    for(int i = 1; i < size; i++){
      if(key == map[i][j]) // 다음값과 같다면 +1
        colMax++;
        
      else{ // 다르다면 값 업데이트 후 나머지값 초기화
        maxResult = max(maxResult, colMax);
        colMax = 1;
        key = map[i][j];
      }
    }
    maxResult = max(maxResult, colMax); // 열이 끝나면 업데이트
  }
  
  return maxResult;
}