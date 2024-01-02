/*  다음과 같이 번호를 매기고 판별
     2
0
        3
   1

1   3

0   2   */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isSqare;

int lengthSqare(int x1, int y1, int x2, int y2);
void compareLine(vector < vector <int> > &point, int iLine, int a, int b);

//정렬 기준 함수
bool cmp(vector<int> &v1, vector<int> &v2){
  if(v1[1] == v2[1])
    return v1[0]>v2[0];
  else return v1[1]>v2[1];
}

int main() {
  int iTestCase, iLine, iTempLine;
  vector<vector<int>> point(4, vector<int>(2));
  
  cin >> iTestCase;
  
  for(int i = 0; i < iTestCase; i++){
    
    isSqare = true;
    
    for(int j = 0; j < 4; j++){
      cin >> point[j][0] >> point[j][1];
    } 
    
    //끝나는 시간 기준으로 정렬
    sort(point.begin(), point.end(), cmp);

    //길이가 같은지 판별
    iLine = lengthSqare(point[0][0], point[0][1], point[1][0], point[1][1]);
    
    compareLine(point, iLine, 0, 2);
    compareLine(point, iLine, 1, 3);
    compareLine(point, iLine, 2, 3);
  
    // 90도 인지 확인(피타고라스 정리)
    int a = lengthSqare(point[0][0], point[0][1], point[1][0], point[1][1]);
    int b = lengthSqare(point[0][0], point[0][1], point[2][0], point[2][1]);
    int c = lengthSqare(point[1][0], point[1][1], point[2][0], point[2][1]);

    if(a + b != c) isSqare = false;
    
    if(isSqare) cout << "1" << "\n";
    else cout << "0" << "\n";
  }
}

int lengthSqare(int x1, int y1, int x2, int y2){
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);  
}

void compareLine(vector < vector <int> > &point, int iLine, int a, int b){
  
  int iTempLine = lengthSqare(point[a][0], point[a][1], point[b][0], point[b][1]);

  if(iLine != iTempLine){
    isSqare = false;
  }
}