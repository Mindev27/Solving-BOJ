#include <iostream>

using namespace std;

int main() {
  int iEventNum, iLineNum, iFrontInfo, iBackInfo;
  int iTestCase, iPrintStart, iPrintEnd;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> iEventNum >> iLineNum;

  //2차원 배열 동적 할당
  int **history = new int*[iEventNum + 1];
  for(int i = 0; i < iEventNum + 1; i++){
    history[i] = new int[iEventNum + 1]();
  }
  
  //정보 입력
  for(int i = 0; i < iLineNum; i++){
    cin >> iFrontInfo >> iBackInfo;

    //-1이면 i -> j, 1이면 i <- j
    history[iFrontInfo][iBackInfo] = -1;
    history[iBackInfo][iFrontInfo] = 1;
  }

  //플로이드 워셜
  for(int k = 1; k <= iEventNum; k++){
    for(int i = 1; i <= iEventNum; i++){
      for(int j = 1; j <= iEventNum; j++){

        if(history[i][j] == 0){

          // i -> k -> j 라면
          if(history[i][k] == 1 && history[k][j] == 1){
            history[i][j] = 1;
            history[j][i] = -1;
          }  

          // i <- k <- j 라면
          if(history[i][k] == -1 && history[k][j] == -1){
            history[i][j] = -1;
            history[j][i] = 1;
          }
        }
      }
    }
  }

  cin >> iTestCase;

  for(int i = 0; i < iTestCase; i++){
    cin >> iPrintStart >> iPrintEnd;
    cout << history[iPrintStart][iPrintEnd] << "\n";
  }

  delete [] history; //동적할당 해제
}