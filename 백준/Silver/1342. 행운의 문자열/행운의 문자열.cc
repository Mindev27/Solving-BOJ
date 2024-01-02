#include <iostream>
#include <vector>

using namespace std;

string word;
int result = 0;
int alpha[30] = {};
bool visited[15] = {};
vector<char> v;

bool check() {
  for (int i = 0; i < word.size() - 1; i++)
    if(v[i] == v[i + 1]) return false;
  return true;
}

void findString(int depth) {
  if (depth == word.size()) {
    if(check()) result++;
    return;
  }

  for(int i = 0; i < word.size(); i++){
    if(!visited[i]){
      visited[i] = true;
      v.push_back(word[i]);
      findString(depth + 1);
      v.pop_back();
      visited[i] = false;
    }
  }
}

int factorial(int k) {
  if(k == 1) return 1;
  return k * factorial(k - 1);
}

void solve() {
  findString(0);

  // 중복을 빼주기 위해 각 알파벳의 개수 팩토리얼로 나누기
  for (int i = 0; i < word.size(); i++)
    alpha[word[i] - 'a']++;

  for(int i = 0; i < 30; i++){
    if(alpha[i]) result /= factorial(alpha[i]);
  }
  
  cout << result;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> word;
  solve();

  return 0;
}