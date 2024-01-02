#include <iostream>
#include <vector>
using namespace std;

int main() {
  int k, result, holeS;
  vector<pair<int, int>> v;

  cin >> k;
  
  for(int i = 0; i < 6; i++){
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));

  }

  //앞의 6번을 중복하게 push
  for(int i = 0; i < 6; i++){
    v.push_back(make_pair(v[i].first, v[i].second));
  }

  for(int i = 0; i < 6; i++){
    if(v[i].first == v[i+2].first && v[i+1].first == v[i+3].first){
      holeS = v[i+1].second * v[i+2].second;
      result = v[i+4].second * v[i+5].second;
      break;
    }
  }

  result -= holeS;
  result *= k;

  cout << result;
}