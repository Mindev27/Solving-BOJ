#include <iostream>

using namespace std;

int main() {
  int n, m, leaf = 0;

  cin >> n >> m;
  
  for(int i = 1; i < n; i++){
    //필요한 만큼 루프노드에서 만들고
    if(leaf < m){
      cout << "0 " << i << "\n";
      leaf++;
    }
    //나머지를 한쪽에 쭉 몰아넣기
    else{
      cout << leaf << ' ' << i << "\n";
      leaf = i;
    }
    
  }
}