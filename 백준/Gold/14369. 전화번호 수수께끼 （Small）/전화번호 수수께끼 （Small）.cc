#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

string num[10] = {
  "ZERO","ONE","TWO","THREE",
  "FOUR","FIVE","SIX",
  "SEVEN","EIGHT","NINE"
};
bool isOK = false; // 찾았는지 여부
string word;
int caseNum = 1;

// 백트래킹으로 문자열을 만들고 정렬된 문자를 비교
void makeString(string cur, string result) {
  if(isOK || cur.size() > word.size()) return;
  
  if(cur.size() == word.size()){
    sort(cur.begin(), cur.end());
    if(cur == word){
      isOK = true;
      sort(result.begin(), result.end());
      cout << "Case #" << caseNum << ": " << result << "\n";
    }
    return;
  }

  for(int i = 0; i <= 9; i++)
    makeString(cur + num[i], result + to_string(i));
}

void solve() {
  isOK = false;
  sort(word.begin(), word.end());

  for(int i = 0; i <= 9; i++) {
    string cur = num[i];
    makeString(cur, to_string(i));
    if(isOK) break;
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while(T--) {
    cin >> word;
    solve();
    caseNum++;
  }

  return 0;
}
