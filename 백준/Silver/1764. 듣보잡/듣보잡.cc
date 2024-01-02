#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  map<string, int> m;
  int a, b;
  cin >> a >> b;

  //처음 입력 map에 저장
  for(int i = 0; i < a; i++){
    string key;
    cin >> key;
    m.insert({key, 1});
  }

  //중복되는 사람 ans에 추가
  vector<string> ans;
  for(int i = 0; i < b; i++){
    string findName;
    cin >> findName;
    
    if (m.find(findName) != m.end())
    	ans.push_back(findName);
  }

  //사전순 정렬 후 출력
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << "\n";
  }
}