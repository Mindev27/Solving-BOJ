#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

double Area(int a, int b, double rad);

int main() {
  int n;
  vector<int> v;
  
  cin >> n;
  
  double rad = 2 * PI / n; // 중심에서 라디안 단위의 각도

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  double result = 0;
  
  // 정렬 후 0,1 / n,n-1 미리 계산
  result += Area(v[0], v[1], rad);
  result += Area(v[v.size() - 1], v[v.size() - 2], rad);

  // 두 칸씩 띄어가며 더하기
  for(int i = 0; i < v.size() - 2; i++){
    result += Area(v[i], v[i + 2], rad);
  }

  cout << fixed << setprecision(3) << result;
}

double Area(int a, int b, double rad){
  double area = a * b * sin(rad) / 2;
  return area;
}
