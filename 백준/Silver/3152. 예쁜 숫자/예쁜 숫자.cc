#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll p;
ll n[4];
bool isOK = false;

void input() {
  cin >> p;
  for(int i = 0; i < 4; i++) {
    cin >> n[i];
  }
}

bool isPretty(ll x) {
  int one = 0; // 나머지가 1인 개수
  int two = 0; // 나머지가 2인 개수
  int a = 0;
  
  while(x > 0) {
    a = x % p;
    if(a >= 3) return false;

    else{
      if(a == 1) one++;
      else if(a == 2) two++;
    }
    x /= p;
  }

  // 2로 남은게 있을때는 1이 1개여야 유일함
  if(two > 0 && one == 1) return true;
  
  // 2로 남은게 없을때는 1이 2개야 유일함
  if(two == 0 && one == 2) return true;

  return false;
}

void solve() {
  for(int i = 0; i < 4; i++){
    if(isPretty(n[i])) cout << "1 ";
    else cout << "0 ";
  }
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}