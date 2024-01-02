#include <iostream>

using namespace std;

void solve(string num) {
  int result = 2;
  
  for(int i = 0; i < num.length(); i++){
    if(num[i] == '1') result += 2;
    else if(num[i] == '0') result += 4;
    else result += 3;
  }

  result += num.length() - 1;
  cout << result << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true){
    string a; cin >> a;
    if(a == "0") break;
    solve(a);
  }
  
  
  return 0;
}
