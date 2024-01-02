#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  const int SIZE = 50;
  int n, sum;
  int Adata[SIZE]={}, Bdata[SIZE]={};

  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> Adata[i];
  }
  
  for(int i = 0; i < n; i++){
    cin >> Bdata[i];
  }

  sort(Adata, Adata + n);
  sort(Bdata, Bdata + n);
  reverse(Bdata, Bdata + n);

  sum = 0;
  
  for(int i = 0; i < n; i++){
    sum += Adata[i] * Bdata[i];
  }

  cout << sum;
}