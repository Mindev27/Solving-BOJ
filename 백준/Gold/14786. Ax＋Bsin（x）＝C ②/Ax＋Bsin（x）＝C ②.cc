#include <iostream>
#include <cmath>

using namespace std;

int a, b, c;

void solve(){
  long double start = (c - b) / (double)a;
  long double end   = (c + b) / (double)a;
  long double mid;

  // 이분탐색
  while(start < end){

    mid = (start + end) / 2.0;
    
    if(mid < (c - b * (long double)sin(mid)) / (double) a){
      start = mid + 0.0000000000001;
    }
    else if(mid > (c - b * (long double)sin(mid)) / (double) a){
      end = mid - 0.0000000000001;
    }
  }

  cout<<fixed;
  cout.precision(15);
  cout << mid;
}

int main() {

  // freopen("input.txt", "r", stdin);
  
  cin >> a >> b >> c;

  solve();
}