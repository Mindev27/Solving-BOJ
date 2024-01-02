#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int m, res = 99999;
  int data[3000][4];
  string word;
  cin >> m >> word;
  
  for(int i = 1; i <= m; i++){ // mod i로 인덱스 값 바꾸기

    memset(data, 0, sizeof(data));
    
    for(int j = 0; j < word.length(); j++){
      int idx = j % i; // 어떤 알파벳인지 저장

      if(word[j] == 'A')
        data[idx][0]++;
      if(word[j] == 'C')
        data[idx][1]++;
      if(word[j] == 'G')
        data[idx][2]++;
      if(word[j] == 'T')
        data[idx][3]++;
    }

    // 탐색하며 최소개수 찾기
    int change = 0;
    for(int j = 0; j < i; j++){
      int sum = data[j][0] + data[j][1] + data[j][2] + data[j][3];
      int maxNum = max(max(max(data[j][0], data[j][1]), data[j][2]), data[j][3]);

      change += sum - maxNum;
    }

    res = min(res, change);
  }

  cout << res;
}