#include <iostream>
#include <map>
#include <vector>
#include<cctype>

using namespace std;

int main() {
  int siteNum, questionNum;
  string siteInput, passwordInput;
  map<string, string> m;
  vector<string> ans;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> siteNum >> questionNum;

  for(int i = 1; i <= siteNum; i++){
    cin >> siteInput >> passwordInput;

    m.insert(make_pair(siteInput, passwordInput));
  }

  for(int i = 0; i < questionNum; i++){
    cin >> siteInput;
    cout << m.find(siteInput)->second << "\n";
  }
}