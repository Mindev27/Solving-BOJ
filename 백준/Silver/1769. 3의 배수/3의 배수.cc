#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void solve(string word) {
  if(word.length() == 1){
    cout << cnt << '\n';
    if((word[0] - '0') % 3 == 0)
      cout << "YES";
    else cout << "NO";
    return;
  }

  long long temp = 0;
  for(int i = 0; i < word.size(); i++){
    temp += word[i] - '0';
  }
  cnt++;
  solve(to_string(temp));
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  solve(s);


  return 0;
}
