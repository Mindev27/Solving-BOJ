#include <iostream>
#include <cmath>

using namespace std;

int startX, startY, endX, endY, cnt;

void passPlanet(int x, int y, int r){
  bool is_startin = false, is_endin = false;

  //시작지점이 안에 있는지 확인
  if(pow(x-startX, 2) + pow(y-startY, 2) < pow(r,2)) 
    is_startin = true;

  //끝지점이 안에 있는지 확인
  if(pow(x-endX, 2) + pow(y-endY, 2) < pow(r,2)) 
    is_endin = true;

  //XOR 비트연산을 통해 둘의 상태가 다르다면 cnt에 +1
  if(is_startin ^ is_endin) 
    cnt++;
}

int main(){
  
  int iTestCase, iPlanetNumber, iPlanetX, iPlanetY, iPlanetR;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> iTestCase;
  
  for(int j = 0; j < iTestCase; j++){
    
    cin >> startX >> startY >> endX >> endY;
    cin >> iPlanetNumber;
    
    cnt = 0; //지나는 횟수 초기화
    
    for(int i = 0; i < iPlanetNumber; i++){
      
      cin >> iPlanetX >> iPlanetY >> iPlanetR;
  
      passPlanet(iPlanetX, iPlanetY, iPlanetR);
    }
  
    cout << cnt << "\n";
  }
}