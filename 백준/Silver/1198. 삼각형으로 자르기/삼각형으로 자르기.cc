#include <iostream>

using namespace std;

double Tri_S(int x1, int y1, int x2, int y2, int x3, int y3)
{
  return double(abs(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3)) / 2;
}

int main(){
  int iPoint, iTestCase, data[35][2];
  double S, max;
  
  cin >> iPoint;

  for(int i = 0; i < iPoint; i++){
    cin >> data[i][0] >> data[i][1];
  }

  max = 0.0f;
  
  for(int i = 0; i < iPoint; i++){
    for(int j = i+1; j < iPoint; j++){
      for(int k = j+1; k < iPoint; k++){
        S = Tri_S(data[i][0], data[i][1], data[j][0], data[j][1],data[k][0], data[k][1]);
        if(max < S) max = S;
      }
    }
  }
  cout<<fixed;
  cout.precision(1);
  cout << max;
}