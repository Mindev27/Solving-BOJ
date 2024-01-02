#include <iostream>

using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(true){
    int a, b;
    cin >> a >> b;

    if(a == 0 && b == 0) break;
    cout << a + b << '\n';
  }
}