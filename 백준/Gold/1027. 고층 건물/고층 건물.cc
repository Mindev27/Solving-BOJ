#include <iostream>

using namespace std;

//두점을 지나는 기울기
double incline(int a, int a_H, int b, int b_H){
  return double(b_H - a_H) / (b - a);
}

int main() {
  int iBuilding, max, height[51] = {}, Building[51] = {0,};;
  double max_incline, temp_incline;
  const int initial_incline = -1000000001;

  cin >> iBuilding;
  
  for(int i = 0; i < iBuilding; i++){
    cin >> height[i];
  }

  for(int i = 0; i < iBuilding; i++){

    max_incline = initial_incline;
    
    for(int j = i+1; j < iBuilding; j++){

      //(i, j)를 지나는 기울기
      temp_incline = incline(i, height[i], j, height[j]);

      //지금까지 기울기값보다 더 크다면
      if(max_incline < temp_incline){
        max_incline = temp_incline;
        Building[i] += 1;
        Building[j] += 1;
      }
    }
  }

  max = 0;
  for(int i = 0; i < iBuilding; i++){
    if(max < Building[i]) max = Building[i];
  }

  cout << max;
}