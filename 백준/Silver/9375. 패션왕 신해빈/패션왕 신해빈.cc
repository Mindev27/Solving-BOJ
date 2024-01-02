#include <iostream>
#include <map>

using namespace std;

map<string, int> m; // 카테고리, 개수

void input() {
  int n;
  cin >> n;

  m.clear();
  
  for(int i = 0; i < n; i++){
    string name, tag;
    cin >> name >> tag;

    if (m.find(tag) == m.end()) { // map에 없다면 넣기 
      m.insert({tag, 1});
    }
    else { // 있다면 개수 더하
      m[tag] += 1;
    } 
  }
}

int solve() {
  // 맵을 탐색하면서 (개수 + 1)을 곱해주기
  int result = 1;
  for(auto iter = m.begin(); iter != m.end();  iter++){
    int num = iter->second;
    result *= num + 1;
  }

  result -= 1;
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testCase;
  cin >> testCase;

  while(testCase--){
    input();

    cout << solve() << "\n";
  }
}