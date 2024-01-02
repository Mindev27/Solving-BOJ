#include <iostream>
#include <map>
#include <vector>
#include<cctype>

using namespace std;

int main() {
  int pocketNum, questionNum;
  string input;
  map<string, int> m;
  vector<string> v, ans;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> pocketNum >> questionNum;

  for(int i = 1; i <= pocketNum; i++){
    cin >> input;
    v.push_back(input);
    m.insert(make_pair(input, i));
  }

  for(int i = 0; i < questionNum; i++){
    cin >> input;

    if(isdigit(input[0])){
      cout << v[stoi(input) - 1] << "\n";
    }
    else{
      cout << m.find(input)->second << "\n";
    }
  }
}