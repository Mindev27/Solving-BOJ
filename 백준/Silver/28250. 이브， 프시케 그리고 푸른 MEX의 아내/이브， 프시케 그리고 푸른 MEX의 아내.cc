#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  long long int num0 = 0, num1 = 0, num2 = 0, n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    if(temp == 0) num0++;
    else if(temp == 1) num1++;
    else num2++;
  }

  long long int mexSum = 0;
  
  if(num0 >= 2){
    mexSum += num0 * (num0 - 1) / 2;
  }
  
  mexSum += num0 * num1 * 2;
  mexSum += num0 * num2;

  cout << mexSum;
}
