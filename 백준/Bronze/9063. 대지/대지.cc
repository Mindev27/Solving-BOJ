#include <iostream>

using namespace std;

int main() {
  int iBeat, tempX, tempY, minX, maxX, minY, maxY;
  int width, length, Area;
  cin >> iBeat;

  //초기 좌표값을 설정
  cin >> tempX >> tempY;
  
  minX = maxX = tempX;
  minY = maxY = tempY;

  //첫번째 값을 입력했으므로 iBeat - 1 번 반복
  for(int i = 0; i < iBeat - 1; i++){
    cin >> tempX >> tempY;

    //각 값들을 초기화
    minX = minX > tempX ? tempX : minX;
    maxX = maxX < tempX ? tempX : maxX;

    minY = minY > tempY ? tempY : minY;
    maxY = maxY < tempY ? tempY : maxY;
  }

  width  = maxX - minX;
  length = maxY - minY;

  Area = width * length;
  
  cout << Area;
}