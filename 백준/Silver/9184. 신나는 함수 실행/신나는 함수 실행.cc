#include <iostream>
#include <cstring>

using namespace std;

int a, b, c;
int memo[21][21][21] = {};

int solve(int a, int b, int c){
  if(a <= 0 || b <= 0 || c <= 0) return 1;
    
  if(a > 20 || b > 20 || c > 20)
    return solve(20, 20, 20);

  if(memo[a][b][c] != 0) 
    return memo[a][b][c];
      
  else if(a < b && b < c){
    return memo[a][b][c] = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
  }
  else{
    return memo[a][b][c] =  solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  memset(memo, 0, sizeof(memo));
  
  while(true){
    cin >> a >> b >> c;

    if(a == -1 && b == -1 && c == -1) break;

    cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
  }
  
}